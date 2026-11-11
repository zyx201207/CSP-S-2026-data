#include<bits/stdc++.h>
using namespace std;
long long a[500010],q[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	for(int i = 1;i<=n;i++)q[i] = a[i]-a[i-1];
	long long l = 1,sum = 0,mx = 0;
	for(int i = 2;i<=n;i++){
		sum = sum+q[i]*(i-l);
		if(sum>m){
			sum = sum-(a[i]-a[l]);
			l++;
		}
		else mx = max(mx,i-l+1);
	}
	cout<<mx;
	return 0;
}
