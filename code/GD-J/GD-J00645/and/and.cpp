#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100011]; 
long long sum,cnt,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cnt=a[i];
		int t=m,j=i+1;
		while(t--){
			cnt=cnt&a[j];
			j++;
		}
		sum=max(sum,cnt);
	}
	cout<<sum;
	return 0;
}
