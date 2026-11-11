//赛百味??????
#include <iostream>
#include <algorithm>
#include <queue>
#define mian main
#define maxn 2000006
#define inf 2147483647
/*>-<*/

using namespace std;

void get(__int128 &a){
	long long tmp;
	cin>>tmp;
	a=tmp;
}

void print(__int128 a){
	if(a<0){
		putchar('-');
		a=-a;
	}
	if(a>9){
		print(a/10);
	}
	putchar(a%10+'0');
}

//背的int128模版好像没用上._.
//希望如此 

int tot,head[maxn],nxt[maxn],to[maxn],wgt[maxn],dist[maxn],vis[maxn];

long long c,n,m,d,q,wt,con,st,go,k;
int totp=0;

void adde(int f,int t,int w){
//	cout<<"build "<<f<<' '<<t<<'\n';
	nxt[++tot]=head[f];
	to[tot]=t;
	head[f]=tot;
	wgt[tot]=w;
}

//阅读理解我恨你 
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > list; 
int dij(int f,int t){
//	cout<<"finding:"<<f<<' '<<t<<'\n';
	for(int i=0;i<=totp;i++){
		dist[i]=inf;
		vis[i]=0;
	}
	list.push(make_pair(f,0));
	while(!list.empty()){
		int now=list.top().first;
		int ndis=list.top().second;
		list.pop();
//		cout<<"now："<<now<<':';
		if(vis[now]) continue;
		vis[now]=1;
		for(int it=head[now];it;it=nxt[it]){
//			cout<<" "<<to[it]<<' '<<dist[to[it]];
			if(vis[to[it]]) continue; 
			if(ndis+wgt[it]<dist[to[it]]){
				dist[to[it]]=ndis+wgt[it];
				list.push(make_pair(to[it],dist[to[it]]));
			}
		} 
//		cout<<'\n';
	}
	return dist[t];
}

int mian(){
//	freopen("subway1.in","r",stdin);
//	freopen("subway2.in","r",stdin);
//	freopen("subway3.in","r",stdin);
//	freopen("subway4.in","r",stdin);
//	freopen("subway5.in","r",stdin);
//	freopen("subway6.in","r",stdin);
//	freopen("subway7.in","r",stdin);
//	freopen("subway8.in","r",stdin);
//	freopen("subway9.in","r",stdin);
//	freopen("subway114.in","r",stdin);
//	freopen("subway514.in","r",stdin);
//	freopen("subway1919.in","r",stdin);
//	freopen("subway810.in","r",stdin);
//	freopen("return 1.in","r",stdin);
//	freopen("mystrious action catcher.in","r",stdin);
//	freopen("int mian","r",stdin);

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		totp++;
		cin>>wt;//xixi wo yao ba qiaokelikaizhedaizifangzaizhuozishang,rangxiangqidaochupiao,chansinimenhahahahahahaha(evilerest people)
		adde(totp,totp+1,wt);
		adde(totp+1,totp,wt);
		totp++;
	}
	for(int i=0;i<n;i++){
		cin>>k;
		totp++;
		for(int j=0;j<k;j++){
			cin>>con>>wt;
			adde(totp,con*2,wt);
			adde(con*2,totp,wt);
		}
	}
	for(int i=0;i<q;i++){
		cin>>st>>go;
		cout<<dij(st*2-1,go*2-1)<<'\n';
	} 
	
	
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
/*
(附件:A+B_problem_ac.png) 
这个语言，只有这种程度吗?
本人python玩家，久仰这款语言的大名。经常有人拿c++的指针和python的面向对象比。
今天试玩了半小时。说实话，开发者的思路确实非常人，意料之外确在情理之中。
可是，就只有这种程度了吗？说实话，我很失望。
如果只有这种程度的话，给我十天，十天，我就能akIOI。
（我错了背的不熟不要暴打我嘤嘤嘤我是蒟蒻） 
*/ 
