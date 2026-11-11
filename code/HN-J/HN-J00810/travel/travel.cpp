#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int s=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		cout<<1;
		if(b[0]==d[0]&&d[1]==b[1]){
			cout<<1;
			int i=3;
			if(b[i]<='C'&&d[i]<='C'){
				if(b[i]-d[i]=='B'-'A'||d[i]-b[i]=='B'-'A')
					cout<<1<<1;
					else {
						cout<<1<<0;
					}
				}
			else if(b[i]>='D'&&d[i]>='D'){
				cout<<1<<1;
			}
			else cout<<0<<0;
		}
		
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
}
 
