#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,c;
	char b,d;	
	cin>>n;
	if(n==2){
		cin>>a>>b>>c>>d;
		if(b==d)
			cout<<0;
		else
			cout<<1;
	}
	else
		cout<<0;
	return 0;
}
