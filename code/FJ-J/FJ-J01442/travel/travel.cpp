#include<bits/stdc++.h>
using namespace std;
char a[30],b[30],c[30],d[30];
int main(){	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int i;
	cin>>a>>b>>c>>d;
	for(i=0;i<2;i++){
		if(a[i]!=c[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	if(b[0]==d[0]&&b[1]==d[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')){
		
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