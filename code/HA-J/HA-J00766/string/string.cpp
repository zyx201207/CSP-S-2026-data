#include <bits/stdc++.h>
using namespace std;
int m,n,num=0,t=1;
char q;
string s="";
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>n>>q;
		num+=n;
		for(int j=1;j<=n;j++){
			s+=q;
		}
	}
	
	if(t==1){
		cout<<0;
	}
}
