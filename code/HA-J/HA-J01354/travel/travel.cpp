#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a[6],b[6];
	int flag=0;
	cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>b[1]>>b[2]>>b[3]>>b[4]>>b[5];
	if(a[1]!=b[1]||a[2]!=b[2]){
		cout<<"0000";
		return 0;
	}
	if(a[3]!=b[3]||a[4]!=b[4]){
		cout<<"1000";
		return 0;
	}
	if((a[5]-'A'<=2&&b[5]-'A'<=2)||(a[5]-'A'>2&&b[5]-'A'>2)){
		flag=1;
	}
	else{
		cout<<"1100";
		return 0;
	}
	if(a[5]-b[5]==-1||a[5]-b[5]==1) cout<<"1111";
	else cout<<"1110";
	return 0;
 }  
