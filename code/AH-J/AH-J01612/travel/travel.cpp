#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char c1,c2;
	scanf("%d %d%c %d %d%c",&a,&b,&c1,&c,&d,&c2);
//	cout<<a<<" "<<b<<" "<<c1<<" "<<c<<" "<<d<<" "<<c2;
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if((c1<='C')+(c2<='C')==2||(c1<='C')+(c2<='C')==0){
//				cout<<(c1<='C')+(c2<='C');
				cout<<1;
				if(abs(c1-c2)==1){
					cout<<1;
				}
				else cout<<0;
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
