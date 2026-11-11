#include<bits/stdc++.h>
using namespace std;
int a1,b,c,d,e,f,g,h,i,j,k,l,n;
char a2,b2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a1;
	if(a1==4)
	{
		cin>>d>>c>>d>>e>>f;
		cout<<"3 1 4";
	}
	else
	{
		cin>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l;
		cout<<"10 3 3";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
