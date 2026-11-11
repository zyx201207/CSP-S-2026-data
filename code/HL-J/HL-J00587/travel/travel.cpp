#include<bits/stdc++.h>
using namespace std;
string a,b;
long long ca,cb;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>ca>>a>>cb>>b;
	if(ca!=cb){
		cout<<"0000";
		return 0;
	}
	if(a[0]!=b[0]||a[1]!=b[1]){
		cout<<"1000";
		return 0;
	}
	if(a[2]<=b[2]){
		swap(a[2],b[2]);
	}
	if(a[2]!='D'){
		if(a[2]-b[2]==1){
			cout<<"1111";
			return 0;
		}
		cout<<"1110";
		return 0;
	}
	
	cout<<"1100";
	return 0;
}
