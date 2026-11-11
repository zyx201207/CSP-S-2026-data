//Trick||Treat!
#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	for(int i=0;i<a.size();i++){
		if(a[i]!=c[i]){
			f=0;
		}
	}
	if(f==1){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
		cout<<1;
	}else if(b[2]>='D'&&b[2]<='|F'&&d[2]>='D'&&d[2]<='F'){
		cout<<1;
	}else{
	cout<<0<<0;
	return 0;
	}
	if(b[2]-d[2]==1||d[2]-b[2]==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
