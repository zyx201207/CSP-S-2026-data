#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int t;
	char b;
	for(int i=1;i<=n;i++){
		cin>>t>>b;
		for(int j=1;j<=t;j++){
			a+=b;
		}
	}
	for(int i=0;i<=a.size()/2;i++){
		if(a[i]!=a[a.size()-i]) ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

