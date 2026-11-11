#include <bits/stdc++.h>
using namespace std;
struct p{
	string c;
	string s;
}a[15];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>a[i].c >>a[i].s ;
	}
	if(a[1].c ==a[2].c ){
		cout<<"1";
		int flag=0;
		for(int j=0;j<2;j++){
			if(a[1].s[j]!=a[2].s [j]){
				flag=1;
				cout<<"0";
				break;
			}
		}
		if(flag==0){
			cout<<"1";
		}
		int f=0;
		if(flag==0&&(a[1].s [2]>='D')&&(a[2].s [2]>='D')||flag==0&&(a[1].s [2]<='C')&&(a[2].s [2]<='C')){
			cout<<"1";
			f=1;
		}
		else{
			cout<<"0";
		}
		if(f==1&&flag==0&&(a[1].s[2]+1==a[2].s [2]||a[2].s [2]+1==a[1].s [2])){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	else{
		for(int i=1;i<=4;i++){
			cout<<"0";
		}
	}
	return 0;
}
