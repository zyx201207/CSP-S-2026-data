#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string a,b;
	cin>>n>>a>>m>>b;
	if(n==m){
		cout<<1;
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<1;
			int pa=a[2]-'A'+1;
			int pb=b[2]-'A'+1;
			if(pa<=3&&pb<=3||pa>=4&&pb>=4){
				cout<<1;
				if(pa-pb==1||pa-pb==-1){
					cout<<1;
				}else if(pa==4&&pb==6||pa==6&&pb==4){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
