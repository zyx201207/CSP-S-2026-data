#include <bits/stdc++.h>
using namespace std;
string a,b,n,m;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m){
	cout<<1;
		if(a[0]-'0'+a[1]-'0'==b[0]-'0'+b[1]-'0'){
			cout<<1;
			if((a[2]-'A'<=2 && b[2]-'A'<=2) || (a[2]-'A'>2 && b[2]-'A'>2)){
				cout<<1;
				if(abs(a[2]-b[2])==1 && !((a[2]=='C' && b[2]=='D') || (b[2]=='C' && a[2]=='D')))cout<<1;
				else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
