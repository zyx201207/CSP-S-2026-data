#include<bits/stdc++.h>
using namespace std;
string a,b;
int n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a;
	cin>>m>>b;
	int a1=(a[0]-'0')*10+a[1]-'0';
	int b1=(b[0]-'0')*10+b[1]-'0';
	if(n==m){
		cout<<'1';
		if(a1==b1&&n==m){
			cout<<'1';
			if(!((a[2]=='C'&&b[2]=='D')||(a[2]=='D'&&b[2]=='C'))){
				cout<<'1';
				if(a[2]-b[2]==1||a[2]-b[2]==-1){
					cout<<'1';
				}else{
					cout<<'0';
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else cout<<"0000";
	return 0;
}
