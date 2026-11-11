#include<bits/stdc++.h>
using namespace std;
long long n,a[200000+25],p,ans,q=1;
string s,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=q;j<=q+a[i];j++){
			b[j]=s[i];
		}
			q+=a[i];
	}
	p=q/2;
	if(q%2==0){
		for(int i=1;i<=p;i++){
			if(b[p+i]!=b[p-i+1]) ans++;  
		}
		cout<<ans;
	    return 0;
	}
	else{
		for(int i=1;i<=p;i++){
			if(b[p+i+1]!=b[p-i+1]) ans++;
		}
		cout<<ans;
	    return 0;
	}
}
