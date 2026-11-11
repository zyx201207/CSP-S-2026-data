#include<bits/stdc++.h>
using namespace std;
long long a[200010];
string b[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	long long res=0,cnt=n;
	for(int i=1;i<=n;i++){
		if(i>=cnt) break;
		if(b[i]!=b[cnt]){
			res+=min(a[i],a[cnt]);
		}
		a[i]-=min(a[i],a[cnt]);
		a[cnt]-=min(a[i],a[cnt]);
		if(a[i]!=0) i--;
		if(a[cnt]==0) cnt--;
	}
	cout<<res;
	return 0;
}
