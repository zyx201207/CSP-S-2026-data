#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[2000000];
	char c[2000000];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<"0";
			return 0;
		}
		cout<<min(a[1],a[2]);
		return 0;
	}
	if(n==3){
		if(c[1]==c[2]&&c[2]==c[3]){
			cout<<"0";
			return 0;
		}
		if(c[1]==c[3]){
			cout<<"0";
			return 0;
		}
		if(c[1]==c[2]){
			cout<<a[3];
			return 0;
		}
		if(c[2]==c[3]){
			cout<<a[1];
			return 0;
		}
	}
	if(n==4){
		if(c[1]==c[2]&&c[2]==c[3]&&c[3]==c[4]){
			cout<<"0";
			return 0;
		}
		if(c[1]==c[4]){
			cout<<min(c[2],c[3]);
		}
	}
	return 0;
}
