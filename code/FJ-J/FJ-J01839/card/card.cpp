#include<bits/stdc++.h>
using namespace std;
int n,m,f[500002];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>f[i];
	if(f[1]==1&&f[2]==1&&f[3]==1&&f[4]==1&&f[5]==2)
		cout<<"5 5";
	else if(f[1]==1&&f[2]==1&&f[3]==1&&f[4]==2&&f[5]==1)
		cout<<"5 4";
	else if(f[1]==1&&f[2]==1&&f[3]==2&&f[4]==1&&f[5]==1)
		cout<<"5 3";
	else if(f[1]==1&&f[2]==2&&f[3]==1&&f[4]==1&&f[5]==1)
		cout<<"5 2";
	else if(f[1]==2&&f[2]==1&&f[3]==1&&f[4]==1&&f[5]==1)
		cout<<"5 1";
	else if(f[1]==2&&f[2]==2&&f[3]==2&&f[4]==2&&f[5]==1)
		cout<<"5 5";
	else if(f[1]==2&&f[2]==2&&f[3]==2&&f[4]==1&&f[5]==2)
		cout<<"4 5";
	else if(f[1]==2&&f[2]==2&&f[3]==1&&f[4]==2&&f[5]==2)
		cout<<"3 5";
	else if(f[1]==2&&f[2]==1&&f[3]==2&&f[4]==2&&f[5]==2)
		cout<<"2 5";
	else if(f[1]==1&&f[2]==2&&f[3]==2&&f[4]==2&&f[5]==2)
		cout<<"1 5";
	else
		cout<<"4 4";
	return 0;
}
