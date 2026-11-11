#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	ios::sync_with_stdoi(0);
//	cin.tie(0);
	string cc1,cc2,ss1,ss2;
	cin>>cc1>>ss1>>cc2>>ss2;
	if(cc1==cc2){
		cout<<1;
		if(ss1[0]==ss2[0]&&ss1[1]==ss2[1]){
			cout<<1;
			if(((ss2[2]>='A'&&ss2[2]<='C')&&ss1[2]>='A'&&ss1[2]<='C')||((ss2[2]>='D'&&ss2[2]<='E')&&ss1[2]>='D'&&ss1[2]<='E')){
				cout<<1;
				int a=(int)ss1[2],b=(int)ss2[2];
				if(a==b+1||b==a+1){
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
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
} 
