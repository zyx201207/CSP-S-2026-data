#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n1,n2;
	string c1,c2;
	cin>>n1>>c1>>n2>>c2;
	if(n1==n2)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	string m1,m2;
	char p1,p2;
	for(int i=0;i<2;i++){
		m1+=c1[i];
		m2+=c2[i];
	}
	p1=c1[2];
	p2=c2[2];
	if(m1==m2)cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if(p1>='A'&&p1<='C'){
		if(p2>='A'&&p2<='C')cout<<1;
		else{
			cout<<0<<0;
			return 0;
		}
	}
	if(p1-1==p2||p2-1==p1)cout<<1;
	else cout<<0;
}
