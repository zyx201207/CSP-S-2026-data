//GZ-J00370 贵阳市第十八中学 曹语心 
#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f=0;
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]){
			cout<<"0000";
			return 0;
		}
		f=1;
	}
	if(f) cout<<1;
	f=0;
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]){
			cout<<"000";
			return 0;
		}
		f=1;
	}
	if(f) cout<<1;
	if(b[2]<='C'&&b[2]>='A'&&d[2]<='C'&&d[2]>='A'||b[2]<='E'&&b[2]>='D'&&d[2]<='E'&&d[2]>='D'){
		cout<<1;
		if(abs(int(b[2])-int(d[2]))==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<"00";
	}
	return 0;
} 
