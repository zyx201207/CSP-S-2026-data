#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,k;
char s,p,q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>s>>n>>m>>p;
	if(a==n){
		cout<<1;
		if(b==m){
			cout<<1;
			if((s>='D'&&p>='D')||(s<='C'&&p<='C')){
				cout<<1;
				if(s==p+1||p==s+1){
					cout<<1;
					return 0;
					
				}else{
					cout<<"0";
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
	}else{
		cout<<"0000";
		return 0;
	}
} 
