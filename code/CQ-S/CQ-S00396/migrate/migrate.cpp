#include<bits/stdc++.h>
using namespace std;
//暴力！！！！奇迹！！！！40' 
/*
Trick||Treat!
Oct31==Dec25?
Merry Christmas! & Merry Halloween!

Coconut      5s[loadon]
Super 
这是椰子树上的球，可以在最后一击造成极高伤害。 
生命：2187000
伤害：2187
最终伤害：109350000

Soldier Ant Egg 1s+5s[loadon]
Super
它可以孵化并生成一些有趣的东西……
宠物：x3兵蚁(Ultra) aa.
*/
long long d,x[5001];
int c,t,n;
vector<int>v[5001];
void MLE(){
	deque<long long>d1q[10000];
	deque<long long>dq2[10000];
	deque<long long>d3q[10000];
	deque<long long>dq4[10000];
	deque<long long>d5q[10000];
	deque<long long>dq6[10000];
	MLE();
}
queue<int>q;
int sp[5001],wy[5001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//freopen
	cin>>c>>t;
	if(c>10){
		MLE();
		return 0;
	}
	while(t--){
		cin>>n>>d;long long ans=0ll;
		for(int i=1;i<=n;i++)cin>>x[i],v[i].clear();
		int p=n;
		for(int i=n;i;i--){
			while(x[p]-x[i]>d)p--;
			for(int j=i+1;j<=p;j++){
				v[i].push_back(j);
				v[j].push_back(i);
			}
		}
		for(int i=1;i<=n;i++){
			memset(sp,0x7f,sizeof sp);
			memset(wy,0x00,sizeof wy);
			sp[i]=0;wy[i]=1;q.push(i);
			while(q.size()){
				int h=q.front();q.pop();
				for(int t:v[h]){
					if(sp[t]<=sp[h])continue;
					if(sp[t]==sp[h]+1)wy[t]+=wy[h];
					if(sp[t]>sp[h]+1){
						q.push(t);
						sp[t]=sp[h]+1;
						wy[t]=wy[h];
					}
				}
			}
			for(int j=1;j<=n;j++)if(wy[j]==2)ans++;
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}
