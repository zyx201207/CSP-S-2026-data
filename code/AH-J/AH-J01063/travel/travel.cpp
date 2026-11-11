#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b;
int x,y,n,m;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>x>>a>>y>>b;
	if(a==b&&x==y){
		cout<<"0000";
		return 0;
	}
	bool flag1=false;
	if(x==y){
		cout<<1;
		flag1=true;
	}
	else cout<<0;
	n=(a[0]-'0')*10+a[1]-'0';
	m=(b[0]-'0')*10+b[1]-'0';
	bool flag2=false;
	if(n==m&&flag1){
		cout<<1;
		flag2=true;
	}
	else cout<<0;
	char c=a[2],d=b[2];
	bool flag3=false;
	if((((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C'))||((c=='D'||c=='E')&&(d=='C'||d=='D')))&&flag2){
		cout<<1;
		flag3=true;
	}
	else cout<<0;
	if(abs(c-d)==1&&flag3)cout<<1;
	else cout<<0;
	return 0;
}
