#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	int a=0,b=0;
	char n,m;
	for (char c:s1){
		if ('0'<=c && c<='9') a=a*10+c-'0';
		else n=c;
	}
	for (char c:s2){
		if ('0'<=c && c<='9') b=b*10+c-'0';
		else m=c;
	}
	
	if (c1==c2){
		cout<<1;
		if (a==b){
			cout<<1;
			if (('A'<=n && n<='C' && 'A'<=m && m<='C') || ('D'<=n && n<='F' && 'D'<=m && m<='F')){
				cout<<1;
				if (('A'<=n && n<='C' && 'A'<=m && m<='C' && abs(m-n)==1) || ('D'<=n && n<='F' && 'D'<=m && m<='F')){
					cout<<1;
				}
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
