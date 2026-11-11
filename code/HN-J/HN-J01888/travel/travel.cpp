#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int n,m,i;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	while(i<c.size()){
		if(c[i]>='A'&&c[i]<='Z')break;
		n=n*10+c[i]-'0';
		i++;
	}
	i=0;
	while(i<d.size()){
		if(d[i]>='A'&&d[i]<='Z')break;
		m=m*10+d[i]-'0';
		i++;
	}
	if(a==b){
		cout<<'1';
		if(n==m){
			cout<<'1';
			if((c[2]<='C'&&c[2]>='A'&&d[2]<='C'&&d[2]>='A')||(c[2]<='F'&&c[2]>='D'&&d[2]<='F'&&d[2]>='D')){
				cout<<'1';
				if((c[2]=='F'&&d[2]=='D')||(c[2]=='D'&&d[2]=='F')||(c[2]=='A'&&d[2]=='B')||(c[2]=='B'&&d[2]=='A')||(c[2]=='B'&&d[2]=='C')||(c[2]=='C'&&d[2]=='B')){
					cout<<1;
				}
				else cout<<'0';
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
