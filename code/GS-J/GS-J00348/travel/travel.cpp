#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char c,s;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>c2>>c>>s1>>s2>>s;
	if(c1==s1){
		cout<<1;
		if(c2==s2){
			cout<<1;
			if((c<='C'&&s<='C')||(c>='D'&&s>='D')){
				cout<<1;
				if(c+1==s+0||c-1==s+0){
					cout<<1;
				}else{
					if((c=='D'&&s=='F')||(c=='F'&&s=='D'))
						cout<<1;
					else{
						cout<<0;
					} 
				}
					
			}else
				cout<<"00";
		}else
			cout<<"000";
	}else
		cout<<"0000";
	return 0;
}

