#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int i=0,ans=0;
	while(i<n){
		int l=i,r=i,k=0,ansi=0,li=i;
		while(a[r+1]==a[i] && r!=n-1) r++,ansi++;
		i=r+1;
		while(k<=m){
			if(l==0 && r==n-1) break;
			if(k+a[r+1]-a[li]>m && k+a[li]-a[l+1]>m) break;
			if(l==0){
				k+=a[++r]-a[li];
				ansi++;
			}else if(r==n-1){
				k+=a[li]-a[--l];
				ansi++;
			}else if((a[r+1]-a[i])>(a[i]-a[l-1])){
				k+=a[li]-a[--l];
				ansi++;
			}else{
				k+=a[++r]-a[li];
				ansi++;
			}
		}
		ansi++;
		ans=max(ans,ansi);
	}
	cout<<ans;
	return 0;
}
