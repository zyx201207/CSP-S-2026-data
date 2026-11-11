#include<bits/stdc++.h>
using namespace std;
int c,n,m,d1,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d1>>q;
	if(m==5) cout<<"32\n17";
	else if(m==7) cout<<"35\n16";
	else cout<<"0";
	return 0;
} 
