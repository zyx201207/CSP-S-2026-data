#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt1;
long long a[500001],b[500001],maxans=-1,ans,chahe,cha;
bool p1=1,p2=1;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);	
	for(long long i=1;i<=n;i++){
		cnt1+=a[n]-a[i];
		if(a[i]!=i)p1=0;
		if(a[i+1]-a[i]!=a[i+2]-a[i+1]&&i<=n-2)p2=0;
	}
	if(cnt1<=m){
		cout<<n;
		return 0;
	}
	if(p1){
		long long cnt=0;
		for(long long i=0;i<1010;i++){
			cnt+=i;
			if(cnt>m){
				cout<<i;
				return 0;
			}	
		}
	}
	if(p2){
		long long cnt=0,c=a[2]-a[1];
		for(long long i=0;i<10100;i+=c){
			cnt+=i;
			if(cnt>m){
				cout<<i/c;
				return 0;
			}	
		}
	}
	for(long long i=1;i<=n;i++){
		chahe=0,ans=0;
		for(long long j=i;j>=1;j--){
			cha=a[i]-a[j];
			if(chahe+cha<=m){
				chahe+=cha;
				ans++;
			}
		}	
		maxans=max(maxans,ans);
	}
	cout<<maxans;
	return 0;
}
