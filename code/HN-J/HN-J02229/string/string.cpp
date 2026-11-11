#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,n,s=0,m=0,z1=0;
	char b,z;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		z1+=a;
		if(z!=b){
			m=(max(m,s));
			z=b;
			s=0;
		}
		s+=a;
	}
	m=max(m,s);
	if(z1==m) cout<<0;
	else if(z1/2<=m) cout<<z1/2;
	else cout<<m;
	return 0;
}
