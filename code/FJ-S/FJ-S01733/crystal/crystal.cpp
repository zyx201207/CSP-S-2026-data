#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int n;
long long m,Ans=-1;
void check(long long mid){
	long long cnt=0,ans=0;
	for(int i=n;i>=1;i--){
		if(a[i]>mid)continue;
		cnt+=mid-a[i];
		if(cnt>m){
			break;
		}else{
			ans++;
		}
	}
	Ans=max(ans,Ans);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long tx=1e12,td=-1e12;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tx=min(tx,a[i]);
		td=max(td,a[i]);
	}
	for(int i=tx;i<=td;i++){
		check(i);
	}
	cout<<Ans<<"\n";
	return 0;
}
