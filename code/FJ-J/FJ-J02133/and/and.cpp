#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
string s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+m);
	ans=a[m];
	for(int i = m;i>= m-n;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
