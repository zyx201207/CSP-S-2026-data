#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=0;i<1;i++){
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
	}
	else{
		cout<<0000;break;
	}
	if((b[0]==d[0]&&b[1]==d[1])){
	cout<<1;	
	}
	else{
	cout<<000;break;
	}
	if((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F')){
		cout<<1;
	}
	else{
	cout<<00;break;	
	}
	if(max(b[2],d[2])-min(b[2],d[2])==1){
		cout<<1;
	}91781367
	else{
	cout<<0;break;	
	}
	break;
	}
	return 0;
}//¨€¨~¨}¨|¨{¨z¨y¨x¨ˆ¨ˆ¨ˆ
