#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[1000001]={0},ans=0,aa=0;
	char b[1000001]={0};
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d%c",a[i],b[i]);
	for(int i=1;i<=n;i++){
		if(a[i]%2==0)ans+=a[i]/2;
		else aa++;
	}
	if(aa==1||aa==0)cout<<ans;
	else cout<<0;
}
