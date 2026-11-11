#include<bits/stdc++.h>
using namespace std;
string s;
int n,a[200001];
long long ans;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];		
	}
	for(int i=1;i*2-1<=n;i++){
		if(c[i]!=c[n-i+1]){
			ans+=a[i];
			a[n-i]=a[n-i]-(a[i]-a[n-i+1]);
		}
	}
	cout<<ans;
	return 0;
}
