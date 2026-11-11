#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,ans=1;
	cin>>n;
	int a[n+5];
	char c[n+5],c1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	c1=c[1];
	for(int i=1;i<=n;i++){
		if(c[i]!=c1){
			ans=0;
			break;
		}	
	}
	if(ans==0) cout<<cnt/2;
	else cout<<"0";
	return 0;
}
