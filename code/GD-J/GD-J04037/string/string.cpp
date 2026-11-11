#include<bits/stdc++.h>
using namespace std;

int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,a[100005],num=0,ans=0;
	char c[100005];
	string x,y;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
		for(int j=0;j<a[i];j++){
			 x+=c[i];
		}
}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<a[i];j++){			
			y+=c[i];  
		}
	}
	for(int i=num-1;i>=0;i--){
		if(a[i]!=a[num-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}


