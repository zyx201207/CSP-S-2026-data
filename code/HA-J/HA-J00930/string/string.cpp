#include<bits/stdc++.h>
using namespace std;
long long n;
long long a,ans=0,cnt=0;
char b[200200],c[200200],b2[200200];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		cin>>b[i];
		for(int i=0;i<a;i++){
			b2[i]==b[cnt];
		}
		cnt++;
	}
	for(int i=0;i<n/2;i++){
		c[i]==b[i];
	}
	for(int i=n-1;i>=n/2+1;i--){
		c[i]==b[i];
	}
	for(int i=0;i<n;i++){
		cout<<c[i];
		if(c[i]!=b2[i]){
			ans++;
		}
	}cout<<ans;
	return 0;
}
