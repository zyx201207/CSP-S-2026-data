//疑似DP，不急先睡会儿10:01
//10:15想出了线性做法，难道今天能AK？？！！先上个厕所去了
//10:18上厕所要登记吓哭了，什么时候学校月考也能检查这么严就好了，全甜蜜作弊的 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x(0),sign(1);
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()){
		if(ch=='-'){
			sign=-1;
		}
	}
	for(;isdigit(ch);ch=getchar()){
		x=x*10+ch-'0';
	}
	return x*sign;
}
int n,m; 
int a[500005];
namespace sub12_25{
	void work(){
		int ans[5005];
		memset(ans,0,sizeof(ans));
		for(int f=1;f<=n;++f){
//			cout<<f<<"~"<<n<<endl;
			bool vis[5005];
			memset(vis,0,sizeof(vis));
			stack<int> stk;
			for(int i=f;i<=n;++i){
//				cout<<"i="<<i<<endl;
				int u=a[i];
				if(vis[u]){
					while(!stk.empty()){
						int v=stk.top();
						stk.pop();
						vis[v]=0;
//						cout<<v<<"出"<<endl;
						if(v==u){
							break;
						}
					}
				}
				stk.push(u);
//				cout<<u<<"入"<<endl;
				vis[u]=1;
			}
			while(!stk.empty()){
//				cout<<stk.top()<<"++"<<endl; 
				ans[stk.top()]++;
				stk.pop();
			}
		}
		for(int i=1;i<=m;++i){
			printf("%d ",ans[i]);
		}
		return;
	}
}
bool dandiao=1; 
bool vis[100005];
int ans[500005];
namespace subA{
	void work(){
//		cout<<"ok"<<endl;
		memset(vis,0,sizeof(vis));
		memset(ans,0,sizeof(ans));
		for(int i=n;i>=1;--i){
			if(!vis[a[i]]){
				vis[a[i]]=1;
//				cout<<a[i]<<':'<<i<<endl;
				ans[a[i]]=i;
			}
		}
//		cout<<"ok"<<endl;
		for(int i=1;i<=m;++i){
			printf("%d ",ans[i]);
		}
		return;
	}
}
int main(){//10:46看错题了，前面那个做法伪了 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
		if(a[i]<a[i-1]){
			dandiao=0;
		}
	}
	if(m==1){//注意到m==1时肯定每局都保留1，直接输出n，盲猜有一个点的分(也有可能被盖掉) 
		printf("%d",n);
		return 0;
	} 
	if(n<=5000){//10:53，暂时没有正解思路，先打个暴力分48pts 
		sub12_25::work();
		return 0;
	}
	if(dandiao){//特殊性质A，又多了4pts 
//		cout<<"ok"<<endl;
		subA::work();
		return 0;
	}
	printf("先帝创业未半而骈死于槽枥之间，今天下三分，益州疲弊，此诚危急存亡之秋也。然侍卫之臣不懈于内，忠志之士望身于外者，盖追先帝之殊遇，欲报之于陛下也。");
	printf("诚宜开张圣听，以光先帝遗德，恢弘志士之气，不宜妄自菲薄，引喻失义，以塞忠谏之路也。\n");
	printf("宫中府中，俱为一体，陟罚臧否，不宜异同。若有作奸犯科即为忠善者，宜付有司论其刑赏。\n中间忘了\n臣本布衣，躬耕于南阳，苟全性命于乱世，不求闻达于诸侯，先帝不以臣卑鄙\n");
	printf("猥自枉屈，三顾臣于草庐之中，臣不胜受恩感激，遂许先帝以驱驰。后值倾覆，受任于败军之际，奉命于危难之间，往来二十有一年矣。\n后面没时间默了\n欲买桂花同载酒，终不似，少年游！");
	return 0;//欲买桂花同载酒，终不似，少年游！ 
}//11:31放弃了，估分56pts 
/*
4 3
1 2 1 3
*/
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
/*
5 3
1 1 2 2 3
*/
