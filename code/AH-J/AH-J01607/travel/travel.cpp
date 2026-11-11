#include <bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
	int main(){
	freopen ("travel.in","r",stdin);
	freopen ("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m){
			cout<<"1";
			if(a[0]+a[1]==b[0]+b[1]){
				cout<<"1";
				if(a[2]-'0'<='C'-'0'&&b[2]-'0'<='C'-'0'||a[2]-'0'>'C'-'0'&&b[2]-'0'>'C'-'0'){
					cout<<1;
						if(abs((a[2]-'0')-(b[2]-'0'))==1){
							cout<<1;
							} 	else cout<<"0";
					}else {cout<<"00"; return 0;}
				} 
	else{ cout<<"000";
	return 0;}
		} else{
	cout<<"0000"<<endl;	
}
return 0;
}
