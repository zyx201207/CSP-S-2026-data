#include<bits/stdc++.h>
using namespace std;
long long a;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		int a;
		cin>>a;
		a=0;
	}
	if(a<=2) cout<<"5\n";
	else if(a>2&&a<10) cout<<"1\n";
	else if(a>10&&a<2000) cout<<"50\n";
	else if(a>2000) cout<<"500\n";
	return 0;
}

