//GZ-J00136 遵义市第十二中学  李明博 
#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("reavel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[1]==d[1]&&b[0]==d[0]){
			cout<<1;
			bool n=0,m=0;
			if(b[2]=='A'||b[2]=='B'||b[2]=='C')n=1;
			if(d[2]=='A'||d[2]=='B'||d[2]=='C')m=1;
			if(n==m){
				cout<<1;
				if(b[2]-d[2]==1||b[2]-d[2]==-1)cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	fclose(stdin);fclose(stdout);
	return 0;
}
