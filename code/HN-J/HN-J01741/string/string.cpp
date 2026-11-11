#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,b1=0,l,m=0,ans=0;
string b,c,a1,a2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			c[b1]=b[i];
			b1++;
		}
	}
	l=b1;
	if(l%2==1){
		for(int i=0;i<(l-1)/2;i++){
			a1[i]=c[i];
		} 
		for(int i=(l+1)/2;i<l;i++){
			a2[m]=c[i];
			m++;
		}
		for(int i=0;i<(l-1)/2;i++){
			if(a1[i]!=a2[(l-1)/2-1]){
				ans++;
			}
		}
	}
	else{
		for(int i=0;i<l/2;i++){
			a1[i]=c[i];
		} 
		for(int i=l/2;i<l;i++){
			a2[m]=c[i];
			m++;
		}
		for(int i=0;i<l/2;i++){
			if(a1[i]!=a2[l/2-1-i]){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0; 
} 
