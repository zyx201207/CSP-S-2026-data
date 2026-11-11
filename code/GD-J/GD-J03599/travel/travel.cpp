#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int l[4];
	cin>>a>>b>>c>>d;
	if(a==c){
		l[0]=1;
	}
	else l[0]=0;
	string e[b.size()],f[d.size()],g[5]={"A","B","C","D","F"};
	for(int i=0;i<3;i++){
		e[i]=b[i];
		f[i]=d[i];
	}
	if(e[0]==f[0]&&e[1]==f[1]&&l[0]) l[1]=1;
	else l[1]=0;
	if(((e[2]<="C"&&f[2]<="C")||(e[2]>="D"&&f[2]>="D"))&&l[0]&&l[1]){
		l[2]=1;
	}
	else{
		l[2]=0;
	}
	int n[2];
	for(int i=0;i<5;i++){
		if(e[2]==g[i]) n[0]=i;
		if(f[2]==g[i]) n[1]=i;
	}
	sort(n,n+1);
	int k=n[1]-n[0];
	if((l[0])&&(l[1])&&(l[2])&&k==1){
		l[3]=1;
	}
	else l[3]=0;
	for(int i=0;i<4;i++){
		cout<<l[i];
	}
	return 0;
}
