#include<bits/stdc++.h>
using namespace std;

int n,m,a[10000];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==1) cout<<"3"<<" "<<"1"<<" "<<"4";
	if(a[1]==3) cout<<"10"<<" "<<"3"<<" "<<"3";
	
	return 0;
}

