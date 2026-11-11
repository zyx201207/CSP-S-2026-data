// //subway
// //好像是图论
// //我被盯上了
// //什么玩意？？要我开int sub[501][500001]吗?
// //原来是sum(k1-ki)<=500000
// //T2看不懂
// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<queue>
// #include<cstring>
// using namespace std;
// struct s{
// 	int point,val;
// 	const bool operator<(const s&p)const{
// 		return p.val<val;
// 	}
// };
// vector<s>a[564444];
// priority_queue<s>q;
// bool vis[564444];
// long long dist[564444];
// long long tr[564444];
// long long c,n,m,d,q;
// long long read(){
// 	char ch=getchar();
// 	long long res=0,f=1;
// 	while(ch<'0'||ch>'9'){
// 		if(ch=='-')f=-1;
// 		ch=getchar();
// 	}
// 	while(ch>='0'&&ch<='9'){
// 		int kk=ch-48;
// 		res=res*10+kk;
// 		ch=getchar();
// 	}
// 	return res*f;
// }
// void print(long long x){
// 	if(x<0){
// 		putchar('-');
// 		x=-x;
// 	}
// 	if(x>9)print(x/10);
// 	putchar(x%10+48);
// }
// int main()
// {
// 	c=read(),n=read(),m=read(),d=read(),q=read();
// 	//上午的快读写挂了
// 	//哈哈哈
// 	//特别地,若 c = 0,则该测试点为样例。???没看懂
// 	//意思就是 c是摆设咯
// 	//哈哈哈
// 	for(long long i=1;i<=m;i++){
// 		tr[i]=read();//每个地铁站地铁口到站厅的时间
// 	}
// 	for(long long i=1;i<=n;i++){
// 		long long ki;
// 		ki=read();
// 		for(long long j=1;j<=ki;j++){
// 			long long pass;
// 			long long ti;
// 			pass=read(),ti=read();
// 			a[pass].push_back({i,ti});//每个站厅到对应线路站台的时间
// 		}
// 	}
// 	for(int i=1;i<=q;i++){
// 		long long st,ed;
// 		st=read(),ed=read();
// 		memset(dist,0x3f,sizeof dist);
// 		memset(vis,0,sizeof vis);
// 		dist[st]=0;
// 		q.push({st,0});
// 		while(!q.empty()){
// 			s p=q.top();
// 			q.pop();
// 			int pp=p.point,pv=p.val;
// 			//不对有问题??????????
// 			//还有三个小时还有救
// 		}
// 	}
// }








//考虑分层图
//一条地铁线就是一层





































//??
//让我想想??
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
long long c,n,m,d,q1;
int ti[510000];
struct s{
	long long sta,ti1;
};
struct po{
	long long point,val;//point 存储该地铁站需要换乘到的那个线路的那一层里这个站的编号 val存储他换乘过去的时间
	const bool operator<(const po&p1)const{
		return p1.val<val;
	}
};
vector<po>sts[564444];
void add(long long from,long long belong,long long val){
	sts[from].push_back({belong,val});
	return;
}
vector<s>lines[666];//s存储每个地铁线经过的每个站点
priority_queue<po>q;
long long read(){
	char ch=getchar();
	long long f=1;
	long long res=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		int kk=ch-48;
		res=res*10+kk;
		ch=getchar();
	}
	return res*f;
}
bool sameline(long long x,long long y){
	for(int i=1;i<=n;i++){
		bool f1=0,f2=0;
		// cout<<"hi";
		for(auto p:lines[i]){
			if(p.sta==x)f1=1;
			if(p.sta==y)f2=1;
		}
		if(f1==1&&f2==1)return 1;
	}
	return 0;
}
void print(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)print(x/10);
	putchar(x%10+48);
}
long long dist[564444];//从起点到每个站点的最短距离
bool vis[564444];
long long nt=0;
long long have1(long long point1,long long en){
	for(long long i=1;i<=en;i++){
		for(auto t:lines[i]){
			if(t.sta==point1){
				nt=t.ti1;
				return i;
			}
		}
	}
	return -1;
}
long long findf(long long st1){
	for(long long i=1;i<=n;i++){
		for(auto t:lines[i]){
			if(t.sta==st1)return i;
		}
	}
	return -1;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q1=read();
	for(long long i=1;i<=m;i++){
		ti[i]=read();//地铁口到站厅的时间
	}
	for(long long i=1;i<=n;i++){
		long long k1=read();
		for(long long j=1;j<=k1;j++){
			long long aij,tij;
			aij=read(),tij=read();
			lines[i].push_back({aij,tij});//i号线上有aij这个站 到i站台时间为tij 
			if(have1(aij,i)!=-1){//如果之前也有这个点 
				long long preee=have1(aij,i)-1;//之前在那一层 
				long long pree=i-1;//现在是那一层 
				add(aij+preee*d,aij+pree*d,nt+tij);//之前那一层到现在这一层的边权就是上去再下来的边权 
			}
		}
		long long pree=i-1;//同层边 
		for(long long j=1;j<=k1;j++){
			for(long long k=j+1;k<=k1;k++){
				add(j+pree*d,k+pree*d,0);
			}
		}
	}
	// for(int i=1;i<=n;i++){
	// 	cout<<"i:"<<i<<endl;
	// 	for(auto p:lines[i]){
	// 		cout<<p.sta<<" "<<p.ti1<<endl;
	// 	}
	// }
	for(long long i=1;i<=q1;i++){
		long long st,ed;
		cin>>st>>ed;
		//如果两个在一个线上 那么只需要输出进站+出站时间就可以了
		// cout<<sameline(st,ed);
//		if(sameline(st,ed)){
//			print(ti[st]+ti[ed]);
//			putchar('\n');continue;
//		}
		memset(dist,0x3f,sizeof dist);
		memset(vis,0,sizeof vis);
		while(!q.empty())q.pop();
		cout<<findf(st);
		long long kks=(findf(st)-1)*d+st;;
		dist[kks]=0;
		q.push({kks,0});//快乐迪克斯特拉 如果是st的话 得先找到他最先出现在哪条线上 
		while(!q.empty()){
			po p=q.top();
			q.pop();
			long long pp=p.point,pv=p.val;
			if(vis[pp])continue;
			vis[pp]=1;
			for(auto t1:sts[pp]){
				long long np=t1.point,nv=t1.val;
				if(dist[np]>dist[pp]+nv){
					dist[np]=dist[pp]+nv;
					q.push({np,dist[pp]+nv});
				}
			}
		}
		cout<<ti[st]+dist[(findf(ed)-1)*d+ed]+ti[ed]<<'\n';
	}
}

//分层图！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
//同层边权为ti[st]+ti[ed]
//不同层边权就加上换乘
