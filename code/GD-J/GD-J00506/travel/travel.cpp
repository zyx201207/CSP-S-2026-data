#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string a, b, c, d;
	cin>>a>>b>>c>>d;
	//是否在同一节 
	if(a[0]==c[0] and a[1]==c[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	//是否在同一排 
	if(b[0]==d[0] and b[1]==d[1]){
		cout<<1;
		//是否在同一侧
		if(b[2]>='A' and b[2]<='C'){
			if(d[2]>='A' and d[2]<='c'){
				cout<<1;
				if(b[2]-d[2]<=1 and b[2]-d[2]>=-1){
					cout<<1;
				}else{
					cout<<0;
					cout<<0;
				}
			}else{
				cout<<0;
				cout<<0;
				
			}
		}else if(d[2]>='D' and d[2]<='F' and b[2]>='D' and b[2]<='F'){
				cout<<1;
				if(b[2]-d[2]<=1 and b[2]-d[2]>=-1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
				cout<<0;
			}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
	}
	
	return 0;
}
