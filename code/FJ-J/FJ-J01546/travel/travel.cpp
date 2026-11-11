#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b,c,d;
	char n,m;
	cin>>a>>c>>n>>b>>d>>m;
	if(a==b){
		cout<<1;
		if(c==d){
			cout<<1;	
			if(n=='F'&&m=='D'){
				cout<<1<<1;
			}else if(n=='D'&&m=='F'){
				cout<<1<<1;
			}else if(n=='D'||n=='F'){
				cout<<0<<0;
			}else if(m=='D'||m=='F'){
				cout<<0<<0;
			}else{
				cout<<1;
				if(n-m==1||m-n==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}
	}else{
		cout<<0<<0<<0;
	}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
