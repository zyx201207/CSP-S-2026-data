#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		a=int(s1[0]-'0')*10+int(s1[1]-'0');
		b=int(s2[0]-'0')*10+int(s2[1]-'0');
		if(a==b){
			cout<<1;
			if(s1[2]>='D'&&s2[2]>='D'){
				cout<<11;
			}else if(s1[2]<='C'&&s2[2]<='C'){
				cout<<1;
				if(abs(int(s1[2]-s2[2]))==1){
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
