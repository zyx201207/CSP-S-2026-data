#include<bits/stdc++.h>
using namespace std;
int n;
string a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n;i++) cin>>a[i]>>b[i];
	if(n==2){
		if(b[0]==b[1]){
			cout<<"0";
			return 0;
		}
		else{
			cout<<min(a[0],a[1]);
			return 0;
		}
	}
	if(n==3){
		if(b[0]!=b[2]&&b[0]!=b[1]&&b[2]!=b[1]){
			cout<<max(a[0],a[2]);
			return 0;
		}
	}
	return 0;
}
