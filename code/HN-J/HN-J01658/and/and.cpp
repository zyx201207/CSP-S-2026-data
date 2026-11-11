#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,ans;
pair<int,int> a[N]; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].second;
		int jj=a[i].second;
		while(jj>0){
			a[i].first+=jj%2;
			jj/=2;
		}
	}
	sort(a+1,a+n+1);
	ans=a[n].second;
	for(int i=n-1;i>n-m;i--){
		ans&=a[i].second;
	}
	cout<<ans;
	return 0;
} 
