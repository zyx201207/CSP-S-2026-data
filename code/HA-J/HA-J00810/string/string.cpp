#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m[1000000010],w,r=0;
	char a,b,c,d[1000000010],e[1000000010],f;
	cin >>n;
	for(int i=0;i<=n;i++){
		cin>>w>>a;
		if(a!=c){
		r++; c=a;
		}
		m[i]=w;
		e[i]=c;
		while(w!=0){
			b = b+a;
			w--;
		}
	}
	for(int i=0;i<=n;i++){
		f+=m[n-i]*e[n-i];
		d[i]=f;
	}
	for(int j=1;j<=n;j++){
		if(e[j]!=d[j])r++;
	}
	cout<<r-1;
	return 0;
}
