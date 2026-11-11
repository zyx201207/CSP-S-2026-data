#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a1,b1,a2,b2;
	char c1,c2; 
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	if(a1==a2){
		cout<<1;
		if(b1==b2){
			cout<<1;
			if(c1>='A'&&c1<='C'&&c2>='A'&&c2<='C'||c1>='D'&&c1<='F'&&c2>='D'&&c2<='F'){
				cout<<1;
				if(abs(c1-c2)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0<<0;
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
