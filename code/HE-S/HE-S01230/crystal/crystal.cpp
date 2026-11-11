#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,m,acy[MAXN];
long long sum[MAXN];
long long dnf[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>acy[i];
		
	}
	sort(acy+1,acy+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+acy[i];
	}	
	for(int i=1;i<=n;i++){
		dnf[i]=sum[i]-sum[i-1];
	}
	for(int i=1;i<=n;i++){
		dnf[i]=dnf[i]-dnf[i-1];
	}
	sort(dnf+1,dnf+1+n);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(m<=0){
			break;
		}
		else if(dnf[i]<0){
			continue;
		}
		else{
			m-=dnf[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
