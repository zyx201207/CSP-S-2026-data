#include <bits/stdc++.h>
using namespace std;
char c[100000010],y[100000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,cyl=0;
	cin>>a;
	char jy;
	for(int i=0;i<a;i++){
		cin>>c[i];
		cin>>y[i];
		if(i==0){
			jy=y[i];
			cyl++;
		}
		else{
		for(int j=0;j<a;j++){
			if(y[i]==jy){
				cyl++;
				}
			}
		}
	}
	if(cyl>=a){
		cout<<"0";
	}
	else{
		cout<<c[a-2];
	}
	return 0;
}