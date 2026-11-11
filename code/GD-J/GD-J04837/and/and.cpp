#include <bits/stdc++.h>
using namespace std;
const int N =1e5+5;
int n,m,ans,ans2;
int a[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m+i;j++){
			if(j==1){
				ans=a[j];
			}
			ans=max(ans&a[j],ans);
		}
		ans2=max(ans,ans2);
	}
	cout<<ans2;
	return 0;
} 
