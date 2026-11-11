#include<bits/stdc++.h>
using namespace std;
int a[200009],d[200009];
char f[200009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	int n,cnt=0,ant=0;
	string g;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>f[i];
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=a[i];j++){
			g+=f[i];
		}
	}
	if (n!=1){
	
		int len=g.size();
		if(len%2==0)
		len=len;
		else len=len+1;
		for(int i=1;i<=len/2;i++){
			if(g[i]!=g[len-i])
			ant++;}
		cout<<ant;}
		else
		cout<<ant;
		
	return 0;
}
