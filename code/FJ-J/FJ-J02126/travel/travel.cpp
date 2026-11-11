#include<bits/stdc++.h>
using namespace std;
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	char aa,ab,ac,ad,c,d;
	cin>>a>>aa>>ab>>c>>b>>ac>>ad>>d;
	if(a==b){
		cout<<1;
		if(aa==ac&&ab==ad){
			cout<<1;
			if((c>='A'&&c<='C'&&d>='A'&&d<='C')||(c>='D'&&c<='F'&&d>='D'&&d<='F')){
				cout<<1;
				if(abs( (int)c-d )==1){
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
	return 0;
} 
