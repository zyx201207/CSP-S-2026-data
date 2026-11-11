#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string a,b;

signed main(){
	//Trick||Treat!
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//02 01A 02 01B

	cin>>n>>a>>m>>b;
	if(n==m){
		cout<<1;
		if(a[0]==b[0] && a[1]==b[1]){
			cout<<1;
			if((a[2]<='C' && b[2]<='C') || (a[2]>='D' && b[2]>='D')){
				cout<<1;
				if(a[2]==b[2]+1 || a[2]==b[2]-1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0;
				cout<<0;
			}
		}
		else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
} 
