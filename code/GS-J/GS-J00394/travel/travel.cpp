#include<bits/stdc++.h> 
using namespace std;
int main{
	freopen("travel.in","r',stdin);
	freopen("travel.out","w',stdout);
	};int b=0,a=0;
	char c[10],d[10];
	cin>>b>>c>>a>>d;
	if (b==a){
		if (c[0]==d[0] and c[1]==d[1]){
			if (((a[3]=="a" or a[3]=="b" or a[3]=="c")and(b[3]=="a" or b[3]=="b" or b[3]=="c"))or((a[3]=="d" or a[3]=="f")and(b[3]=="d" or b[3]=="f")){
				cout<<"1111"
				}
			}
			else{
				cout<<"1110"
			}
		else{
			cout<<"1100"
		}
	else{
		cout<<"0000"
	}
		}
return 0;
	}
