//GZ-J00221  ¿Ó È∫≠
#include<bits/stdc++.h>
using namespace std;
int n;
int a;
string c;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t=n+1/2;
	int x=1;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		if(c[i]!=c[i-1]){
			x=0;
			cout<<c[i];
		}
		ans+=a;
	}
	if(x)cout<<0;
	else {
		if(ans%2==0){
			cout<<ans/2;
		}
		else cout<<ans-1/2;
	}
	return 0;
}
