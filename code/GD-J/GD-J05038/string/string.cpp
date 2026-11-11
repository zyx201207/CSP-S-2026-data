#include<bits/stdc++.h>
using namespace std;
int f[200005],m[200005]={0};
char g[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0;
	long long b=0;
	char a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i]>>g[i];
	}
	a=g[1];
	for(int j=1;j<=n;j++){
		if(g[j]!=a){
			s++;
			m[j]=f[j];
		}
	}
	if(!s){
		cout<<0;
		return 0;
	}
	else{
		for(int k=1;k<=n;k++){
			b+=m[k];
		}
		cout<<b;
	}
}
