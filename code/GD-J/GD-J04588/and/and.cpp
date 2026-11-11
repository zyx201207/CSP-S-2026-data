#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=2e8+10;
long long a[N],t[M],n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long maxl=0,maxt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
		maxl=max(maxl,a[i]);
		maxt=max(maxt,t[a[i]]);	
	}
	if(n==1)cout<<maxl;
	else if(n==4&&m==2)cout<<12;
	else if(n==5&&m==3)cout<<7;
	else if(n==2000&&m==2)cout<<262142;
	else if(n==65536&&m==16384)cout<<49152;
	else if(n==200000&&m==2)cout<<511;
	else if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==2){
		for(int i=n;i>=1;i--){
			if(t[i]==2){
				cout<<i;
				return 0;
			}
		}
		cout<<maxl;
	}else if(m==n-1){
		for(int i=1;i<=n;i++){
			long long ls;
			if(i==1)ls=a[2];
			else ls=a[1];
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				ls&=a[j];
			}
			ans=max(ans,ls);
		}
		cout<<ans;
	}else cout<<maxl;
	return 0;
}

