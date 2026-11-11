#include<bits/stdc++.h>
using namespace std;
long long a[2000000];
string u[2000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if(m==1){
		long long ans=0;
		for(int i=1;i <= n;i++){
			cin>>a[i];
		}
		for(int i=1;i <= n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}
	return 0;
} 
