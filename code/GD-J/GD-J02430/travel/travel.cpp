#include<bits/stdc++.h>
using namespace std;
bool x[5]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int bs=(b[0]-48)*10+(b[1]-48);
	int ds=(d[0]-48)*10+(d[1]-48);
//	cout<<"ds="<<ds<<"  bs="<<bs<<endl;
	if(a==c) x[1]=1;
	if(x[1]==1){
		if(ds==bs) x[2]=1;
		if(x[2]==1){
			if((b[2]>='D'&&d[2]>='D')||(b[2]<='C'&&d[2]<='C')) x[3]=1;
			if(x[3]==1){
				if(abs(b[2]-d[2])==1) x[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++) cout<<x[i];
	return 0;
} 
