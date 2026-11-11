#include<bits/stdc++.h>
using namespace std;
int q=1,w=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
		
	}
	else{
		cout<<0;
		q=0;
		w=0;
	}
	if(w){
		if(b[0]==d[0]&&b[1]==d[1]){
			cout<<1;
			
		}
		else{
			cout<<0;
			q=0;
		}
	}
	else{
		cout<<0;
		q=0;
	}
	
	if(q){
		if(b[2]!='C'||d[2]!='D'){
			if(abs(b[2]-d[2])==1){
				cout<<11;
			}
			else{
				cout<<10;
			}
			
		}
		else{
			cout<<"00";
		}
	}
	
	else{
		cout<<"00";
	}
	
} 
