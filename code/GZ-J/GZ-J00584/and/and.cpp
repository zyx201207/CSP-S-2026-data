//GZ-J00584，盛诗尧，贵阳市清华中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	int n1=n;
	while(n1--){
		cin>>a[n1];
	} 
	sort(a,a+n,greater<int>());
	
	ans=a[0]&a[1];

	
	if(m>2){
		while(m--){
			ans=int(ans&a[m]);
		}
	}
	cout<<ans;
	return 0;
}
