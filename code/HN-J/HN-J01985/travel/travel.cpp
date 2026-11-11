#include<bits/stdc++.h>
using namespace std;
int n,m;
char a[5],b[5],c[5],d[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>(a+1)>>(b+1)>>(c+1)>>(d+1);
	int kk=1;
	for(int i=1;i<=2;i++) 
		if(a[i]!=c[i]) kk=0;
	if(kk==0){
		cout<<"0000";
		return 0;
	}
	else cout<<1;
	if(b[1]==d[1]&&b[2]==d[2]) cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((b[3]=='C'&&d[3]=='D')||(b[3]=='D'&&d[3]=='C')){
		cout<<"00";
		return 0;	
	}
	else cout<<1;
	if(b[3]-1==d[3]||d[3]-1==b[3])
		cout<<1;
	else cout<<0;
	return 0;
} 
