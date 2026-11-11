#include<bits/stdc++.h>
using namespace std;
long long n,d,lian=0,shu=0,ans;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> d;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			ans++;
			if(ans>=d&&ans>shu){
				shu=a[i];
			}
			if(ans>lian){
				lian=a[i];
			}
		}
		ans=0;
	}
	cout << max(shu,lian);
	return 0;
}
