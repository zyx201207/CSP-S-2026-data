#include<bits/stdc++.h>
using namespace std;
string a,b;
string x,y; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a==b){
		cout<<1;
		if(x[0]==y[0]&&x[1]==y[1]){
			cout<<1;
			if((x[2]-'D'>=0&&y[2]-'D'>=0)||(x[2]<'D'&&y[2]<'D')){
				cout<<1;
				if(abs(int(x[2]-y[2]))==1)cout<<1;
				else cout<<0;
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
