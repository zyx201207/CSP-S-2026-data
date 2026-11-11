//GZ-J00445   遵义市新浦新区滨湖中学   范曾
#include <bits/stdc++.h>
using namespace std;
long long n,a,b,ans=0,cont=0;
string s,x,y;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a>>s;
		cont+=a;
		for(long long j=0;j<a;j++){
			x+=s;
			y+=s;
		}
	}
	for(long long i=0;i<cont/2;i++){
		if(x[i]!=y[cont-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

