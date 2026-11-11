#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
long long n,m,d=0,z=0,k=0;
string a,b;
char c;
cin>>n;
for(int i=1;i<=n;i++){
	cin>>m;
	cin>>c;
for(int j=1;j<=m;j++){
	a[d]=char (c);
	b[d]=char (c);
	d++;
}
}
k=d;
for(int i=0;i<d/2;i++,k--){
		if(a[i]!=b[k]){
			b[k]=a[i];
			z++;
		}
	}
	cout<<z;
return 0;
}

