#include<bits/stdc++.h>
using namespace std;
int n,pos,ii,jj;
long long a[200010],ans,cnt;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i]; 
	}	
	ii=1,jj=n;
	while(1){
		if(ii>=jj) break;
		if(a[ii]==a[jj]){
			if(c[ii]!=c[jj]) ans+=a[ii];
			a[ii]=a[jj]=0;
			ii++,jj--; 
		}else if(a[ii]>a[jj]){
			if(c[ii]!=c[jj]) ans+=a[jj];
			a[ii]=a[ii]-a[jj];
			jj--;
		}else{
			if(c[ii]!=c[jj]) ans+=a[ii];
			a[jj]=a[jj]-a[ii];
			ii++;
		}
	}
	cout<<ans;
	return 0;
}
