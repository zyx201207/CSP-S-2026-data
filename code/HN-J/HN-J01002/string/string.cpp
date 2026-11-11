#include<bits/stdc++.h>
using namespace std;
long long n,b[100000005],ans,js,x;
string c,d,e,f; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>c[i];
		
	}
	x=b[1];
	for(int i=1;i<n;i++){
		x=__gcd(x,b[i+1]);
	} 
	if(x==0)
		x=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<b[i]/x;j++)
			d+=c[i];
		ans+=b[i]/x; 
	}
	for(int i=0,j=ans-1;i<ans/2&&j>=ans/2;i++,j--){
		e+=d[i];
		f+=d[j];
 	}
	if(e==f)	
		cout<<0;
	else{
		for(int i=0;i<ans/2;i++)
			if(e[i]!=f[i])
				js++;
		cout<<js*x;
	}
	return 0;
} 
