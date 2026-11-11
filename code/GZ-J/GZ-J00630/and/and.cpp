//GZ-J00630 张庭赫 贵阳中天中学 
#include<bits/stdc++.h>
using namespace std;

int main(){
	#define int long long
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+5);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.begin()+1+n);
	int sum=a[n];
	for(int i=n-m+1;i<=n;i++){
		sum=(sum&a[i]);
	}
	cout<<sum;
	return 0;
}
