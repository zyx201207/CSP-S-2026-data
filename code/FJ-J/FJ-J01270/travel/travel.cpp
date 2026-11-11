#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	bool ok=1;
	for(int i=0;i<a.size();i++){
		if(a[i]!=c[i]) ok=0;
	}
	if(ok) cout<<1;
	else cout<<0;
	for(int i=0;i<=1;i++){
		if(b[i]!=d[i]) ok=0;
	}
	if(ok) cout<<1;
	else cout<<0;
	if(b[2]<='C' &&d[2]>='D') ok=0;
	if(b[2]>='D' &&c[2]<='C') ok=0;
	if(ok) cout<<1;
	else cout<<0;
	int b_=b[b.size()-1];
	int d_=d[d.size()-1];
	if(b_==65 && d_==67) ok=0;
	if(b_==67 && d_==65) ok=0;
	if(ok){
	 	cout<<1;
	}else{
		cout<<0;
	}
}
