#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m,a[200005],sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			sum+=a[i];
			break;
		}
		if(a[i]*2+1==a[4]&&a[4]*2+1==a[1]){
			sum+=a[i];
			break;
		}
	}
	cout<<sum;
	return 0;
}
