#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],l[N],r[N],s,ans,L;
char f[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	bool ok=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>f[i];
		l[i]=r[i-1]+1;
		r[i]=l[i]+a[i]-1;
		L+=a[i];
//		cout<<l[i]<<" "<<r[i]<<"\n";
	}
	int i=1,mid=L/2;
	s=n;
//	cout<<mid<<" "<<L<<"\n";
	while(l[i]<=mid){
		int l1=l[i],r1=min(mid,r[i]);
		int dj=L-l1+1,di=L-r1+1;
		for(int j=s;j>=1;j--){
			if(r[j]<di){
				s=j;
				break;
			}
			int dql=l[j],dqr=min(r[j],dj);
			bool hjm=0;
			if(l[j]<di){
				dql=di;
				s=j;
				hjm=1;
			}
			if(f[i]!=f[j]) ans+=(dqr-dql+1);
			if(hjm) break; 
		}
		i++;
//		cout<<ans<<" ";
	}	
	cout<<ans;
	return 0;
} 
