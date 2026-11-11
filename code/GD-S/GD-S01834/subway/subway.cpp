/*

思路：
将一条路线上的所有站点视为一个点，站台视为一个点。 
将大图压缩为点数不超过 n+m的图，然后广搜。
 复杂度为q(n+m)
 无法通过最后两个测试点
  A规则特殊优化：
  k=1,该线路为滚木
  k=2 ，等效于一条带权边
  
  退化为m点n边带权最短路 
   且因为联通，n<=500， 
   
   B规则：
   退化为m+n点的无权最短路，广搜 ,可过12-15 
	
	n<=2 特殊处理:
	n=1
	直接算答案
	n=2
	至多转一次，找最便宜的那次或者不用转 
	
	d=2
	退化为单链（每两个点之间有大量单路，预处理缩减为单链n<=500。哈希表处理点顺序，对于每次询问点，先向内走一步，然后顺着单链走） 
	 没时间写这个了 
	//freopen( 
	//freopen( 
	
*/


#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int w[500010];
int k[500010];
int a[510][50010];
int t[510][50010];
int x,y;
int f1[50010];
int f2[501];

struct node{

	int p;//标记边数
	int vt[510];//标记每条边的对应点  
	int wt[501];//价格 
}s1[50010];//站台点 

struct node1{

	int p;//标记边数
	int vt[50010];//标记每条边的对应点 (到每个车站) 
	int wt[50010];//价格 
}s2[510];//路线点 
int h[500510];//记录点的种类 
int st[500510]; //记录点的编号 
bool vit[500510][3];//标记走过的种类和编号 的点 
int ans[500550][3];//标记对于标记点的最短路步数 
int head,tail; 
void init(){
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			//路线点 
			//从编号i的地铁到编号为a[i][j]的地铁站，价格为 t[i][j]
			s2[i].vt[ ++s2[i].p ] = a[i][j]; 
			s2[i].wt[ s2[i].p ] = t[i][j];
			//站点点 
			//从编号为a[i][j]的地铁站到编号i的地铁，价格为 t[i][j]
			s1[a[i][j]].vt[ ++s1[a[i][j]].p ]=i;
			s1[a[i][j]].wt[ s1[a[i][j]].p ]=t[i][j];
		}
		
	} 

} 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	init(); //结构体处理
	int minn1=2e9;
	int minn2=2e9; 
	int minn3=2e9; 
	if(n==2){//专门处理 
		
		for(int j=1;j<=m;j++){//查找最小的换站代价 
			if(s1[j].p==2){
				int b=s1[j].wt[1];
				b+=s1[j].wt[2];
				minn1=min(minn1,b);
			} 
		}
		for(int j=1;j<=m;j++){//查找第二小的换站代价 (当x点是最小换站点的时候用)
			if(s1[j].p==2){
				int b=s1[j].wt[1];
				b+=s1[j].wt[2];
				if(b==minn1) continue;
				minn2=min(minn2,b);
			} 
		}
		for(int j=1;j<=m;j++){//查找第三小的换站代价 (当x点和y点是最小换站点和最小第二点的时候用)
			if(s1[j].p==2){
				int b=s1[j].wt[1];
				b+=s1[j].wt[2];
				if(b==minn1||b==minn2) continue;
				minn3=min(minn3,b);
			} 
		}
		
	} 
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		memset(ans,0,sizeof(ans));
		memset(vit,0,sizeof(vit));
		if(n==1){
			cout<<w[x]+w[y]+s1[x].wt[1]+s1[y].wt[1]<<endl;
			continue;
		}else if(n==2){
			if(s1[x].p==1&&s1[y].p==1){
				if(s1[x].vt[1]==s1[y].vt[1]){//在同一条上 
					cout<<w[x]+w[y]+s1[x].wt[1]+s1[y].wt[1]<<endl;
				}else{//不在同一条上 
					cout<<w[x]+w[y]+s1[x].wt[1]+s1[y].wt[1]+minn1<<endl;//额外加上一个换站代价 
				}
			}else if(s1[x].p==2&&s1[y].p==1){
				if(s1[x].wt[1]+s1[x].wt[2]==minn1){//x是最小换站点，使用第二换站点 
					cout<<w[x]+w[y]+min(s1[x].wt[ s1[y].vt[1]/*直接下y的那条线*/ ],minn2+s1[x].wt[ 2-s1[y].vt[1]/*换乘一次*/])+s1[y].wt[1]<<endl;
				}else{
					cout<<w[x]+w[y]+min(s1[x].wt[ s1[y].vt[1]/*直接下y的那条线*/ ],minn1+s1[x].wt[ 2-s1[y].vt[1]/*换乘一次*/])+s1[y].wt[1]<<endl;
				}
			}else if(s1[x].p==1&&s1[y].p==2){
				//与上同理 
				int u=x;
				x=y;
				y=u;//交换二者，然后使用与上文相同 的公式 
				if(s1[x].wt[1]+s1[x].wt[2]==minn1){//x是最小换站点，使用第二换站点 
					cout<<w[x]+w[y]+min(s1[x].wt[ s1[y].vt[1]/*直接下y的那条线*/ ],minn2+s1[x].wt[ 2-s1[y].vt[1]/*换乘一次*/])+s1[y].wt[1]<<endl;
				}else{
					cout<<w[x]+w[y]+min(s1[x].wt[ s1[y].vt[1]/*直接下y的那条线*/ ],minn1+s1[x].wt[ 2-s1[y].vt[1]/*换乘一次*/])+s1[y].wt[1]<<endl;
				}
				
				
			}else{
				/*
				00 使用最小点判断 
				01使用二点 
				02使用1点 
				03 同3 
				10同2 
				12使用 
				20
				21
				
				*/
				if(s1[x].wt[1]+s1[x].wt[2]==minn1){//x占用1点 
					if(s1[y].wt[1]+s1[y].wt[2]==minn2){//y占用2点 
						//用3点
						 cout<<w[x]+w[y]+min(  s1[x].wt[1]+s1[y].wt[s1[x].vt[1]]  ,   min( s1[x].wt[2]+s1[y].wt[s1[x].vt[2]]  ,  min(s1[x].wt[1]+s1[y].wt[s1[x].vt[2]]+minn3  ,  s1[x].wt[2]+s1[y].wt[s1[x].vt[1]]+minn3)  ))<<endl;
						
					}else{
						//用2点 
						cout<<w[x]+w[y]+min(  s1[x].wt[1]+s1[y].wt[s1[x].vt[1]]  ,   min( s1[x].wt[2]+s1[y].wt[s1[x].vt[2]]  ,  min(s1[x].wt[1]+s1[y].wt[s1[x].vt[2]]+minn2  ,  s1[x].wt[2]+s1[y].wt[s1[x].vt[1]]+minn2)  ))<<endl;
					}
				}else{//x未占用1点 
					if(s1[y].wt[1]+s1[y].wt[2]==minn1){
						if(s1[x].wt[1]+s1[x].wt[2]==minn2){
							cout<<w[x]+w[y]+min(  s1[x].wt[1]+s1[y].wt[s1[x].vt[1]]  ,   min( s1[x].wt[2]+s1[y].wt[s1[x].vt[2]]  ,  min(s1[x].wt[1]+s1[y].wt[s1[x].vt[2]]+minn3  ,  s1[x].wt[2]+s1[y].wt[s1[x].vt[1]]+minn3)  ))<<endl;
						}else{
							cout<<w[x]+w[y]+min(  s1[x].wt[1]+s1[y].wt[s1[x].vt[1]]  ,   min( s1[x].wt[2]+s1[y].wt[s1[x].vt[2]]  ,  min(s1[x].wt[1]+s1[y].wt[s1[x].vt[2]]+minn2  ,  s1[x].wt[2]+s1[y].wt[s1[x].vt[1]]+minn2)  ))<<endl;
						}
					}else{
						cout<<w[x]+w[y]+min(  s1[x].wt[1]+s1[y].wt[s1[x].vt[1]]  ,   min( s1[x].wt[2]+s1[y].wt[s1[x].vt[2]]  ,  min(s1[x].wt[1]+s1[y].wt[s1[x].vt[2]]+minn1  ,  s1[x].wt[2]+s1[y].wt[s1[x].vt[1]]+minn1)  ))<<endl;
					}
				}
				 
			}

			continue;
		}//n<=2特盘 
		
		
		if(d<=2){//做演化算法,
			 
			
		}
		if(c<=6){
			memset(ans,0x3f3f3f3f,sizeof ans);
			head=tail=0;
			h[0]=1;
			st[0]=x;
			vit[x][1]=1;
			ans[x][1]=0; 
			tail++; 
			while(head<tail&&!vit[y][1]){
				int c=h[head];
				int cx=st[head++];
				if(c==1){
					for(int j=1;j<=s1[c].p;j++){
						int nx=s1[c].vt[j];
						if(vit[nx][1-c]) continue;
						vit[nx][1-c]=1;
						ans[nx][1-c]=min(ans[nx][1-c],ans[cx][c]+s1[c].wt[j]);
						h[tail]=1-c;
						st[tail++]=nx;
					}
				}else{
					for(int j=1;j<=s2[c].p;j++){
						int nx=s2[c].vt[j];
						if(vit[nx][1-c]) continue;
						vit[nx][1-c]=1;
						ans[nx][1-c]=min(ans[nx][1-c],ans[cx][c]+s2[c].wt[j]);
						h[tail]=1-c;
						st[tail++]=nx;
					}
				}
				
				cout<<w[x]+w[y]+ans[y][1]<<endl;
			}
		} else if(c>=7&&c<=11){//A特盘，因为不会最短路，下面的广搜代码直接粘贴只是时间*2，可以接受， 我还要写 一个特判 
			memset(ans,0x3f3f3f3f,sizeof ans);
			head=tail=0;
			h[0]=1;
			st[0]=x;
			vit[x][1]=1;
			ans[x][1]=0; 
			tail++; 
			while(head<tail&&!vit[y][1]){
				int c=h[head];
				int cx=st[head++];
				if(c==1){
					for(int j=1;j<=s1[c].p;j++){
						int nx=s1[c].vt[j];
						if(vit[nx][1-c]) continue;
						vit[nx][1-c]=1;
						ans[nx][1-c]=min(ans[nx][1-c],ans[cx][c]+s1[c].wt[j]);
						h[tail]=1-c;
						st[tail++]=nx;
					}
				}else{
					for(int j=1;j<=s2[c].p;j++){
						int nx=s2[c].vt[j];
						if(vit[nx][1-c]) continue;
						vit[nx][1-c]=1;
						ans[nx][1-c]=min(ans[nx][1-c],ans[cx][c]+s2[c].wt[j]);
						h[tail]=1-c;
						st[tail++]=nx;
					}
				}
				
				cout<<w[x]+w[y]+ans[y][1]<<endl;
		
		
		}
		
		
		
		
		}else if(c>=12&&c<=19){//B特盘 
			//h为种类,1为站点，2为道路，st为编号,vit标记路径 
			//ans[i][j]表示到编号为i，种类为j 的点的最短路 ,vit编码方式同理 
			head=tail=0;
			h[0]=1;
			st[0]=x;
			vit[x][1]=1;
			ans[x][1]=0; 
			tail++; 
			while(head<tail&&!vit[y][1]){
				int c=h[head];
				int cx=st[head++];
				if(c==1){
					for(int j=1;j<=s1[c].p;j++){
						int nx=s1[c].vt[j];
						if(vit[nx][1-c]) continue;
						vit[nx][1-c]=1;
						ans[nx][1-c]=ans[cx][c]+1;
						h[tail]=1-c;
						st[tail++]=nx;
					}
				}else{
					for(int j=1;j<=s2[c].p;j++){
						int nx=s2[c].vt[j];
						if(vit[nx][1-c]) continue;
						vit[nx][1-c]=1;
						ans[nx][1-c]=ans[cx][c]+1;
						h[tail]=1-c;
						st[tail++]=nx;
					}
				}
				
				cout<<w[x]+w[y]+ans[y][1]*t[1][1]<<endl;
			}
		
		
		
		}else{//其他 很明显，我不会写带权最短路 ,用广搜凑合一下偏分 
			memset(ans,0x3f3f3f3f,sizeof ans);
			head=tail=0;
			h[0]=1;
			st[0]=x;
			vit[x][1]=1;
			ans[x][1]=0; 
			tail++; 
			while(head<tail&&!vit[y][1]){
				int c=h[head];
				int cx=st[head++];
				if(c==1){
					for(int j=1;j<=s1[c].p;j++){
						int nx=s1[c].vt[j];
						if(vit[nx][1-c]) continue;
						vit[nx][1-c]=1;
						ans[nx][1-c]=min(ans[nx][1-c],ans[cx][c]+s1[c].wt[j]);
						h[tail]=1-c;
						st[tail++]=nx;
					}
				}else{
					for(int j=1;j<=s2[c].p;j++){
						int nx=s2[c].vt[j];
						if(vit[nx][1-c]) continue;
						vit[nx][1-c]=1;
						ans[nx][1-c]=min(ans[nx][1-c],ans[cx][c]+s2[c].wt[j]);
						h[tail]=1-c;
						st[tail++]=nx;
					}
				}
				
				cout<<w[x]+w[y]+ans[y][1]<<endl;
			}
		}
		
	}
	
	
	
	
	
	



	return 0;
}
/*
15:10开始写T2 
哇，还有专门为我们做特殊数据准备的好东西 
	15:50 不好孩子们，这题东西有点多 
	16:00不好孩子们，这道题不能用广搜 
	16:05好的孩子们，好像可以广搜
	16:23 不好孩子们，数据都存不下
	16:36 孩子们，只能拿部分了 
	16:45 ok,理完思路，开始写 
	18:17 SSL0124在搏斗中倒下了
	来听我的心事吧
	打完这一场之后我就打算退役了
	上个高中之后力不从心
	学业压力不小，集训还要占用一天的周末，实在是受不了、
	更不提暑假占了一个月的集训，我到现在还没走出暑假（就像昔涟没能走出翁法罗斯一样）
	再坚持了1个多月之后我也是直接选择打完就退队了，我很喜欢编程，但我的路或许就到这里了，我很不舍，但没有办法了。 
	看到这里的伙伴啊，我祝你快乐，幸福，天天开心，可以找到自己的另一半，度过圆满的一生，或者说，永远不死（bushi）
	 本来想给你唱一首《昔涟》的，但是没有时间写歌词了
	 还有一点，本人初中一模之后350抽6+1遐蝶+sp银狼望周知 。 
*/
