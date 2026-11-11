//GZ-J00719 ◊Ò“Â“ª÷– ∆—Ω‹∫¿ 
#include <bits/stdc++.h>
using namespace std;
long long b[200005];
long long n,ans,ii=1,jj;
char a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	jj=n;
	for(int i=1;i<=n;i++)
	cin>>b[i]>>a[i];
	while(ii!=n/2+1){
	if(a[ii]!=a[jj]){
		if(b[ii]<b[jj]){
		ans+=b[jj]-b[ii];
		b[jj]-=b[ii];
		ii++;
	}else if(b[ii]==b[jj]){
		ii++;jj--;ans+=b[ii];
	}else if(b[jj]<b[ii]){
		ans+=b[ii]-b[jj];
		b[ii]-=b[jj];
		jj--;
	}
	}else {
		ii++;
		jj--;
	}
}
	cout<<ans;
    return 0; 
}

