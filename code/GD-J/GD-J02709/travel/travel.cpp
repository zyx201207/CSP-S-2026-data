#include<iostream>
#include<cstring>
using namespace std;
string a,b,c,d;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			int x=0,y=0;
			if(b[2]-'A'<=2) x=1;
			if(d[2]-'A'<=2) y=1;
			if(x==y){
				cout<<1;
				int p=b[2]-'A',q=d[2]-'A';
				if(p==5) p--;
				if(q==5) q--;
				if(p+1==q||p-1==q) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
