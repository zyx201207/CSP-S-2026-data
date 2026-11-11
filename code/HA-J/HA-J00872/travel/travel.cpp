#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,a,b;
	int x1,x2;
	char y1,y2;
	cin>>c1>>x1>>y1>>c2>>x2>>y2;
	a=y1;
	b=y2;
	if(c1==c2){
		cout<<1;
			if(x1==x2){
			cout<<1;
				if(((a<=67&&b<=67)||(a>67&&b>67))&&a!=b){
					cout<<1;
						if(a-b==1||a-b==-1){
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
