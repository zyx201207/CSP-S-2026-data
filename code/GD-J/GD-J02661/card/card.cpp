#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[500005],ans=1,asn[500005];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for(int i0=1;i0<=n;i0++) {
		for(int i=i0+1;i<=n;i++) {
			for(int j=i-1;ans<=j;j--) {
				if(a[i]==a[j]){
					ans=i;
				}
			}
		}
		for(int j=ans;j<=n;j++)asn[a[j]]++;
		ans=i0+1;
	}
	for(int i=1;i<=m;i++)cout<<asn[i]<<" ";
		
	return 0;
}
