#include<bits/stdc++.h>
using namespace std;
int n,a[200009],k=0,b,s,x,v[200009],p,q,t;
char c[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
		v[i]=v[i-1]+a[i];
	}
	x=(s+1)/2;
	b=(n+1)/2;
	for(int i=1;i<=b;i++){
		if(a[i]==a[n+1-i]&&c[i]!=c[n+1-i])
		{
			k+=a[i];
		}
	}
	for(int i=x;i>=1;i--){
		t=s+1-i;
		for(int j=0;j<=n;j++){
			if(i>v[j]) p=j+1; 
		}
		for(int z=0;z<=n;z++){
			if(t>v[z]) q=z+1; 
		}
		if(p!=q||c[q]!=c[p]) k++; 
	}
	cout<<k;
	return 0; 
}
