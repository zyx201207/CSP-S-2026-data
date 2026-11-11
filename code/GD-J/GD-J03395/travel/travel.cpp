#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string a,b,n,m;
	cin>>a>>n>>b>>m;
	if(a==b){
		cout<<"1";	
		if(n[0]==m[0]&&n[1]==m[1]){
			cout<<"1";	
			if(n[2]<='C'&&m[2]<='C'||m[2]>='D'&&n[2]>='D'){
				cout<<"1";
				if(n[2]+1==m[2]||n[2]-1==m[2]){
					cout<<"1";
				}else cout<<"0";
			}else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
 
