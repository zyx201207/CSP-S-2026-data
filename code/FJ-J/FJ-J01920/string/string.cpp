#include<bits/stdc++.h>
using namespace std;
long long x,y,n,ans=0;
string a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>b;
		y+=x;
		for(int o=1;o<=x;o++){
			a[o]=b[0];
		}
	}
	if(y%2==1){
		y+=1;
	}
	for(int i=1,o=y;i<=(y/2);i++,o--){
		if(a[i]!=a[o]){
			ans+=1;
		}
	} 
	cout<<ans;
	return 0;
}













