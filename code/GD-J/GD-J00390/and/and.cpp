#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200020],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	ans=a[n];
	for(int i=n-1;i>=m;i--){
		ans&=a[i];
	}
	cout<<ans<<endl;
	return 0;
}
