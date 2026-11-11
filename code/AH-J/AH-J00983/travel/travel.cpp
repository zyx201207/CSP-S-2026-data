#include<bits/stdc++.h>
using namespace std;
long long cnt; 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
		cnt++;
	}
	else{
		cout<<0;
	}
	if(cnt==1&&b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
		cnt++;
	}
	else{
		cout<<0;
	}
	if(cnt==2&&((b[2]<=67&&b[2]>=65&&d[2]<=67&&d[2]>=65)||(b[2]<=69&&b[2]>=68&&d[2]<=69&&d[2]>=68))){
		cout<<1;
		cnt++;
	}
	else{
		cout<<0;
	}
	if(cnt==3&&max(b[2],d[2])-min(b[2],d[2])==1){
		cout<<1;
	}
	else{
		cout<<0;
	}
}
