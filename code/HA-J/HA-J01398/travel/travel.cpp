#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c1,c2,a1,a2;
	char s1,s2;
	cin>>c1>>a1>>s1>>c2>>a2>>s2;
	if(c1==c2){
		cout<<1;
		if(a1==a2){
			cout<<1;
			if((s1<='C' && s2<='C') or (s1>'C' && s2>'C')){
				cout<<1;
				if(s1-s2==1 or s2-s1==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0<<0;
			}
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
