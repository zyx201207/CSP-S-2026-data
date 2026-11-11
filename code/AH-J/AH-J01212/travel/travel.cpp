#include<bits/stdc++.h>
using namespace std;
int e[5];
char a[2],b[3],c[2],d[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]=='0'){
		if(a[1]!='1'){
			e[0]=1;
		}
	}
	if(a[0]=='1'){
		if(a[1]!='6')
			e[0]=1;
		}
	if(c[0]==a[0]&&c[1]==a[1])
		e[2]=1;
	else e[0]=0,e[2]=0;
	if(b[0]==d[0]&&b[1]==d[1]){
		if(b[2]==d[2])
			e[1]=0,e[3]=0;
		else{
			if((b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))
				e[1]=1,e[3]=1;
		else
		{
			if((b[2]=='C'&&d[2]=='D')||(b[2]=='D'&&d[2]=='C'))
				e[1]=1,e[3]=0,e[2]=0;
			else{
				if((b[2]+1)==d[2]||(b[2]-1)==d[2])
					e[1]=1,e[3]=1;
				}
			}
		}
	}
	else{
		e[2]=0;
	}
	for (int i=0;i<4;i++){
		cout<<e[i]<<" ";
	}
	return 0;
}
