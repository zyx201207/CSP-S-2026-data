#include<bits/stdc++.h>
using namespace std;
int a[4];
char d[23];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a[0]=0;
	a[1]=0;
	a[2]=0;
	a[3]=0;
	gets(d);
	if(d[0]==d[7]&&d[1]==d[8]){
		a[0]=1;
		if(d[3]==d[10]&&d[4]==d[11]){
			a[1]=1;
			if(d[5]>='A'&&d[5]<='C'&&d[12]>='A'&&d[12]<='C'){
				a[2]=1;
				if(d[5]=='A'&&d[12]=='C'){
					cout<<"1110";
					return 0;
				}
				if(d[5]=='C'&&d[12]=='A'){
					cout<<"1110";
					return 0;
				}
				a[3]=1;
			}
			else if(d[5]>='D'&&d[5]<='E'&&d[12]>='D'&&d[12]<='E'){
				cout<<"1111";
				return 0;
			}
		}
		else{
			cout<<"1000";
			return 0;   	
		} 
	}
	else{
		cout<<"0000";
		return 0;
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}