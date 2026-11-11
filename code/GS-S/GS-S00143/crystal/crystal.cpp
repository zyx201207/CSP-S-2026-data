#include <bits/stdc++.h>
using namespace std;
const int N=500100;
int n;
long long m;
int a[N];
int jieguo=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		long long ans=0;
		int tot=0;
		while(ans<m+1&&i-tot>0){	
			ans+=a[i]-a[i-tot];
			if(ans<m+1||ans==m+1){
				tot++;
			}
		}
		jieguo=max(tot,jieguo);
	}
	cout<<jieguo;
	return 0;
} 
