#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],s[N];
int n;
long long m,ans,sum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int k=ceil(n/2);
	int x=a[k+1];
//	cout<<x<<endl;
	for(int i=1;i<=n;i++){
		if(a[i]==x){
			ans++;
		}
	}
//	cout<<ans<<endl;
	for(int i=k;i>=1;i--){
		if(m-(x-a[i])>=0){
			m-=(x-a[i]);
			ans++;
		}
		else break;
	}
	cout<<ans<<endl;
	return 0;
}
