#include<bits/stdc++.h>
#define online
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
ll a[2000005];
vector<ll> tu[2000005];
ll ru[2000005];
struct st{
	ll v,w;
};
queue<st> que;
int ceng[2000006],tong[2000006];
int main(){
#ifdef online
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
#endif
	ios::sync_with_stdio(0);cin.tie(0);
	int T;cin>>T>>T;
	while(T--){
		ll n,d;cin>>n>>d;
//		cout<<n<<' '<<d<<endl;
		for(int i=1;i<=n;i++) cin>>a[i];sort(a+1,a+1+n);
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
//					cout<<a[j]-a[i]<<' '<<d<<endl;
					tu[i].push_back(j);
				}
			}
		}for(int i=1;i<=n;i++){
			for(int v:tu[i]){
				ru[v]++;
			}
		}ll ans=0;
		while(1){
			for(int i=1;i<=n;i++) ceng[i]=tong[i]=0;
			for(int i=1;i<=n;i++){
				if(ru[i]==0)que.push({i,1}),ceng[i]=1,tong[i]=1;
			}if(que.empty())break;
//			for(int i=1;i<=n;i++) cout<<"RP"<<ru[i]<<' ';cout<<endl;
			while(!que.empty()){
				st idx=que.front();que.pop();
				for(int v:tu[idx.v]){
					if(ceng[v]){
						if(idx.w+1==ceng[v])tong[v]+=tong[idx.v];
					}else{
						ceng[v]=idx.w+1;que.push({v,idx.w+1});
//						cout<<v<<' '<<ceng[v]<<endl;
						tong[v]=tong[idx.v];
					}
				}
			}for(int i=1;i<=n;i++){
			//	cout<<tong[i]<<' ';
				if(tong[i]==2)ans++;
			}//cout<<endl;
			for(int i=1;i<=n;i++){
				if(ru[i]==0)que.push({i,1}),ru[i]--;
			}while(!que.empty()){
				st idx=que.front();que.pop();
				for(int v:tu[idx.v])ru[v]--;
			}
		}cout<<ans<<endl;
		for(int i=1;i<=n;i++) tu[i].clear(),ru[i]=0;
		while(!que.empty())que.pop();
	} 
	
	return 0;
}
/*
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

怎么又是图论？我去？

哦不是的，吓我一跳，我说某某某怎么变得这么那个啥了

但是有点像图论和计数

计数的话。。。我回去了
---
16:38 凯旋归来！ 

OK ,u<v
u能到v，且最短路径（就是最少需要经过的岛屿数量最少）的条数为2

数据很大，2e6。需要设计优秀算法。大概率排除DP的可能。不可能是字符串。

刚好两条...撕...怎么这么熟悉呢？

tarjan似乎就是这样的。但是这道题跟那个没有任何关系。 

先思考一个问题：假设我们要求的是 u v这两个岛（暴力嘛），怎么搞？

先考虑：先按照d来跳，跳到极限，然后停下，边数+1，然后继续跳。这样我们就求得了最少需要的路径。

另外一条就是反着的？考虑本质。

我讨厌计数。

我们可以先计算差分数组：可以获得两两岛屿之间的距离。然而最优的肯定是不停跳跃。

不好做。我们看 T4.

T4也没看出所以然来。 
---
OK，又是上图最短路... 


这是一张 DAG。 
我靠，我搞错了，居然是6:30 结束考试。还有30分钟。。。吓我一跳。 

哦，没清空完，清空一下。 

oh，没开 long long 
---
18:22 打的,n^2，40分拿下！总分212~240分。（因为没有 sub3 的点。） 
*/
