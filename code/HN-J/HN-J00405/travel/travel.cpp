#include<bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("tracel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m){
		cout<<1;
		n=(a[0]-'0')*10+(a[1]-'0'),m=(b[0]-'0')*10+(b[1]-'0');
		if(n==m){
			cout<<1;
			if(a[2]<='C'&&b[2]<='C'||a[2]>='D'&&b[2]>='D'){
				cout<<1;
				if(int(a[2]-b[2]==1)||int(b[2]-a[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
