#include <bits/stdc++.h>
using namespace std;
string r,rs,x,xs;
bool flag=false,fa=false,f=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>rs>>x>>xs;
	if(r[0]==x[0] && r[1]==x[1]){
		cout<<1;
	}else{
		f=true;
		cout<<0;
	}
	if(rs[0]==xs[0] && rs[1]==xs[1] && r==x){
		cout<<1;
	}else{
		cout<<0;
		flag=true;
	}
	if(abs(rs[2]-xs[2])>2 || flag==true){
		fa=true;
		cout<<0;
	}else if(rs[2]=='C' && xs[2]=='D'){
		cout<<0;
		fa=true;
	}else if(xs[2]=='C' && rs[2]=='D'){
		cout<<0;
		fa=true;
	}else{
		cout<<1;
	}
	if( !fa && abs(rs[2]-xs[2])==1){
		cout<<1;
	}else{
		cout<<0;
	}
	
		
}
