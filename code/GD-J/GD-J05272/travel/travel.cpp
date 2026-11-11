#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int n,m;
	string s1,s2;
	cin>>n>>s1>>m>>s2;
	int a=s1[1]-'0'+(s1[0]-'0')*10,b=s2[1]-'0'+(s2[0]-'0')*10;
	if(n==m){
		cout<<1;
		if(a==b){
			cout<<1;
			if((s1[2]<='C' && s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				cout<<1;
				if(s1[2]+1==s2[2] || s1[2]-1==s2[2]){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
			cout<<0;
			cout<<0;
			}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	} else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}

	return 0;
}
