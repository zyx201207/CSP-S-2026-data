#include<bits/stdc++.h>
using namespace std;
long long a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	unsigned long long m,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++){
		if(m>=b[i]){
			ans=i;
			continue;
		}
		break;
	}
	cout<<ans;
	return 0;
}
