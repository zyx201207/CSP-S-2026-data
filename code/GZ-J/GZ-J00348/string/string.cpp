//GZ-J00348 遵义市第十二中学 张晋宁
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	cin>>a;
	long long b,e=0;
	string c;
	char d;
	for(int i=1;i<=a;i++){
		cin>>b>>d;
		for(int j=1;j<=b;j++){
			c+=d;
		}
		e+=b;
	}
	long long ans=0;
	for(long long i=0;i<=e-i-1;i++){
		if(c[i]!=c[e-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
