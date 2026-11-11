#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,ans="";
	cin>>a>>b>>c>>d;
	bool f=true;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i])f=false;
	}
	if(!f){
		cout<<"0000";
		return 0;
	}
	f=true;
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]){
			cout<<"1000";
			return 0;
		}
	}
	bool w,x,y,z;
	if(b[2]>='D')w=true;
	if(b[2]<='C')x=true;
	if(d[2]>='D')y=true;
	if(d[2]<='c')z=true;
	if((w && z) || (x && y)){
		cout<<"1100";
		return 0;
	}
	int i=b[2],j=d[2];
	if(i!=j+1 && j!=i+1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";

	return 0;
}

