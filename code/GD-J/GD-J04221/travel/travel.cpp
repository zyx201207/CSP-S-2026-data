#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	bool f=1,f1=1,f2=0,f3=0;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]){
			f=0;
		}
		if(b[i]!=d[i]){
			f1=0;
		}
	}
	if(f==0){
		cout<<"0000";
		return 0;
	}
	cout<<f<<f1;
	if(f1==0){
		cout<<"00";
		return 0;
	}
	if(((b[2]>='A'&&b[2]<='C')&&(d[2]>='A'&&d[2]<='C'))||(b[2]>='D'&&b[2]<='F')&&(d[2]>='D'&&d[2]<='F')){
		f2=1;
	}
	cout<<f2;
	if(f2==0){
		cout<<"0";
		return 0;
	}
	if((int(b[2]-'A')+1)==int(d[2]-'A')||(int(b[2]-'A')-1)==int(d[2]-'A')){
		f3=1;
	}
	cout<<f3;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
