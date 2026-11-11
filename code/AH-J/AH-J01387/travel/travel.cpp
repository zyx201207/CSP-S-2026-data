#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	string a,b,c,d;
	int n[10]={1,1,1,1,1};
	cin>>a>>b>>c>>d;
	for(int i=0;i<a.size();i++){
		if(a[i]==c[i])continue;
		else n[1]=0;
	}
	if(n[1]==1){
	for(int i=0;i<2;i++){
		if(b[i]==d[i])continue;
		else n[2]=0;
	}
}
else n[2]=0;
	if(n[2]==1){
	if(b[2]>='A'&&b[2]<='C'){
		if(d[2]>='A'&&d[2]<='C'){
			int s=b[2]-'0',m=d[2]-'0';
			if(abs(s-m)!=1)n[4]=0;
		}
		else n[3]=0;
	}
	else if(b[2]=='D'||b[2]=='F'){
		if(d[2]=='D'||d[2]!='F')n[3]=0;
	}
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='D')n[4]=0;
	else if(d[2]>='A'&&d[2]<='C'&&b[2]>='D')n[4]=0;
}
else{
		n[3]=0;
		n[4]=0;
}
	for(int i=1;i<=4;i++)cout<<n[i];
	return 0;
}
