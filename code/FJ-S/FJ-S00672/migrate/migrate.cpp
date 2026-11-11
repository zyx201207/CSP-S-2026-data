#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
const int N=2e6+5;
int t,c,n,d,x[N],jump[N],rejump[N],Fjump[N],root[N],cnt=0;
bool pd(int l,int r){
	return jump[l]>r;
}
bool check(int l,int r){
	int cnt1=0;
	for(int it=l;it<=r;it=jump[it])cnt1++;
	int cnt2=0;
	for(int it=r;it>=l;it=rejump[it])cnt2++;
	if(cnt1==cnt2)
		return 1;
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		queue<int> q;
		for(int i=1;i<=n;i++)
			cin>>x[i];
		for(int i=n;i>=1;i--){
			while(q.size()&&x[q.front()]-x[i]>d)q.pop();
			if(q.size())
				jump[i]=q.front(),
				rejump[q.front()]=i;
				//最远跳跃距离 
			else
				jump[i]=N;//不可达
			q.push(i);
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(check(i,j))cnt++;
		cout<<cnt<<endl;
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				int l=jump[i],r=jump[j];
//				if(pd(i,j)&&pd(l,r)){
//					cnt+=min(jump[i],jump[j]);
//				}
//			}
//		}
	}
	return 0;
}
/*
*/
