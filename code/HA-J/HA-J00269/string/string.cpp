#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string a[10005];
	int n;
	int c=0;
	cin>>n;
	int con=0;
	
	for(int i=0;i<=n-1;i++){
		cin>>c;
		con+=c;
		cin>>a[i];
		for(int j=1;j<=c;j++){
			a[i+j]=a[i];
		}
}
	int ans=0;
	for(int k=0;k<=con;k++){
		if(a[k]!=a[con-k]){
			a[k]=a[con-k];
			ans++;
		}
	}
	cout<<ans;
	
	return 0;	
}
