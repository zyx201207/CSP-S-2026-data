#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	string s,s1;
	cin>>x>>s>>y>>s1;
	int a=(s[0]-'0')*10+s[1]-'0';
	int b=(s1[0]-'0')*10+s1[1]-'0';
	char c=s[2];
	char d=s1[2];
	if(c=='F')c='E';
	if(d=='F')d='E';
	if(x==y){
		cout<<1;
		if(a==b){
			cout<<1;
			if(c<='C'&&d<='C'||c>'C'&&d>'C'){
				cout<<1;
				if(abs(c-d)<=1){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}  
