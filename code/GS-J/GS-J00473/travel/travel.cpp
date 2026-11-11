#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long n,m,a,b;
	string q,w;
	char c,d;
	cin>>n>>q>>m>>w;
	a=(q[0]-48)*10+(q[1]-48);
	b=(w[0]-48)*10+(w[1]-48);
	c=q[2];
	d=w[2];
	//判斷在同一車廂 
	if(n==m){
		cout<<1;
		//判斷在同一排
		if(a==b){
			cout<<1;
			//判斷在同一側 
			if((c<'D' && d<'D') || (c>'C' && d>'C')){
				cout<<1;
				//判斷在鄰座
				if(c>'C' && d>'C'){
					cout<<1;
				}
				else{
					if(c=='B'){
						cout<<1;
					}
					else if(d=='B'){
						cout<<1;
					}
					else{
						cout<<0;
					}
				}
			}
			else{
				cout<<0;
				cout<<0;
			}
		}
		else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0; 
		cout<<0;
	}
	return 0;
}
