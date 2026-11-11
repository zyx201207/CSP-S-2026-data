#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0] && b[1]==d[1]){
			cout<<1;
			int f1=0,f2=0;
			if(b[2]=='A' || b[2]=='B' || b[2]=='C') f1=1;
			else f1=2;
			if(d[2]=='A' || d[2]=='B' || d[2]=='C') f2=1;
			else f2=2;
			if(f1==f2){
				cout<<1;
				if(b[2]==d[2]+1 || d[2]==b[2]+1) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
