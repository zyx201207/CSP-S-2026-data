#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	for(int i=0;i<b;i++){
		cout<<c*d;
		c+=23;
		d-=76;
	}
	return 0;
}
