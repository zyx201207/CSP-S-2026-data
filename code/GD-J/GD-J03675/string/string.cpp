#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,truth=1,ans;
	cin>>n;
	long long a[n+1];
	string c[n+1];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		if(i!=0&&c[i]!=c[i-1]) truth=0;
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	if(n==2){
		if(truth==1) ans=0;
		else {
			if(a[0]>a[1]) ans=a[0]-a[1];
			if(a[1]>a[0]) ans=a[1]-a[0];
		}
		cout<<ans;
	}
	return 0;
}
