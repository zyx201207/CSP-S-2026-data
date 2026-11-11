#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char a1,a2;
	cin>>a>>b>>a1>>c>>d>>a2;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if((('A'<=a1&&a1<='C'&&'A'<=a2&&a2<='C')||(a1=='D'&&a2=='F'||a2=='D'&&a1=='F'))){
				cout<<1;
				if(((a1=='A'&&a2=='B'||a1=='B'&&a2=='A'||a1=='B'&&a2=='C'||a2=='B'&&a1=='C')||(a1=='D'&&a2=='F'||a2=='D'&&a1=='F'))){
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
