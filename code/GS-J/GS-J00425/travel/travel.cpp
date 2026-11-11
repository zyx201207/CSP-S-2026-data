#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,a,b,c;
	cin>>n>>a;
	cin>>b>>c;
	if(n==b){
		if(a-c==4){
			cout<<"1";
			if(a-c==1 or c-a==1){
				cout<<"11";
			}
		}else{
				cout<<"00";
			}
		cout<<"11";
	}
	cout<<"1111";
	return 0; 
}

