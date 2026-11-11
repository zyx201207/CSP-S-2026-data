#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200010];
char b[200010];
int f;
int c[200010];
long long ans;
int main(){
	/*freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);*/
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=(n+1)/2;i++){
		if(b[i]!=b[n-i+1]){
			f=1;
			c[i]=i;
		}
	}
	if(f==0){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=0){
			ans+=a[i];
		}
	}
	cout<<ans;
	return 0;
} 
