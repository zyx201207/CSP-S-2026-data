//GZ-J00322   遵义市新蒲新区滨湖中学 王海涛 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	long long n;
	cin>>n;
	long long a[100000000];
	char b[100000000];
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int l=1,r=n;l<r;l++,r--){
		if(b[l]!=b[r]){
			ans+=max(a[l],a[r]);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0; 
}
