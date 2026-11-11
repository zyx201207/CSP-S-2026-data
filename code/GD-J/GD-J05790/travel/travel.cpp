#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string n1,n2;
	string a,b;
	int t=1;
	cin>>n1>>a>>n2>>b;
	if(n1!=n2||n1=="01"||n1=="16"||n2=="01"||n2=="16"){
		cout<<0<<0<<0<<0;
	}else{
		cout<<1;
		for(int i=0;i<2;i++){
			if(a[i]!=b[i]){
				t=0;
			}
		}
		if(t==0){
			cout<<0<<0<<0; 
		}else{
			cout<<1;
			if((a[2]=='D'&&b[2]=='E')||(b[2]=='D'&&a[2]=='E')){
				cout<<1<<1;
				return 0;
			}else if('A'<=a[2]&&'C'>=a[2]&&'A'<=b[2]&&'C'>=b[2]){
				cout<<1;
				if((a[2]=='A'&&b[2]=='C')||(b[2]=='A'&&a[2]=='C')){
					cout<<0;
				}else{
					cout<<1;
				}
			}else{
				cout<<0<<0;
			}
		}
	}
	return 0;
}
