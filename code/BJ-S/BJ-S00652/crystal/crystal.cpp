#include <bits/stdc++.h>
using namespace std;

long long a[100005];
long long n,m;
int ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	int cnt=m;
	
	while(cnt>0){
	for(int i=1;i<=n/2;i++){
		while(a[i]!=a[i+1] && cnt>0){
			a[i]++;
			cnt--;
		}
	}
	}
	
	
	
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			ans++;
			
		}
		else{
			break;
		}
	}
	
	cout << ans+1;
	return 0;
}
