#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			b[i]+=a[i]-a[j];
		}
	}for(int i=n;i>=0;i--){
		if(b[i]==m){
			cout<<i+1;
			return 0;
		}
	}return 0;
}