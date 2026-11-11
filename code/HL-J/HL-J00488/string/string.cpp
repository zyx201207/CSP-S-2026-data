#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,cnt;
string z,f,zf;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		k=0;
		char o=0;
		cin>>k>>o;
		for(int j=1;j<=k;j++){
			zf+=o;
		}
	}
	//cout<<zf.length()<<endl;
	if(zf.length()%2==0){
		for(int i=0;i<zf.length()/2;i++){
			z+=zf[i];
		}
		for(int i=zf.length()-1;i>=zf.length()/2;i--){
			f+=zf[i];
		}
	}
	else{
		for(int i=0;i<zf.length()/2;i++){
			z+=zf[i];
		}
		for(int i=zf.length()-1;i>zf.length()/2;i--){
			f+=zf[i];
		}
	}
	//cout<<z<<endl<<f;
	for(int i=0;i<z.length();i++){
		if(z[i]!=f[i])
		cnt++;
		else
		continue;
	}
	cout<<cnt;
}
