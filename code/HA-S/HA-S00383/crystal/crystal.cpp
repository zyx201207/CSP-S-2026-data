#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
const ll maxn=1e12+1;
ll a[N];
int cnt;
int num[N];
int n,m;
int cha[N];
map<int,int>mp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	a[0]=maxn;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1]){
			mp[cnt]=a[i-1];
			cnt++;
		}
		num[cnt]++;
	}
	mp[cnt]=a[n];
	mp[0]=mp[1];
	for(int i=1;i<=cnt;i++)cha[i]=mp[i]-mp[i-1];
	ll ans=num[1];
	int cha1[N];
	for(int i=2;i<=cnt;i++){
		int t=i,sum=0,sn=num[t];
		int cha1[N];
		cha1[t]=cha[t];
		while(t!=1){
			cha1[t-1]=cha[t-1]+cha1[t];
			int step=0;
			bool st=0; 
			if(sum+cha1[t]*num[t-1]>m){
				step=(m-sum)/cha1[t];
				st=1;
			}
			else{
				step=num[t-1];
			}
			sum=sum+step*cha1[t];
			sn+=step;
			//cout<<"i="<<i<<" 当前推进到"<<t<<" 向前推进的水晶球个数"<<step<<" 当前的水晶球个数="<<sn<<" 消耗的m="<<sum<<endl;
			t--;
			if(st)break;
		}
		ans=max(ans,(ll)sn);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
