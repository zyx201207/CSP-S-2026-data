#include<bits/stdc++.h>
using namespace std;
long long n,m,arr[500005],s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	if(m==0){
		cout<<0;
		return 0;
	}
	for(long long i=1;i<=n;i++) cin >> arr[i];
	sort(arr+1,arr+1+n);
	for(long long i=2;i<=n;i++) s[i]=arr[i]-arr[i-1];
	for(long long i=2;i<=n;i++){
		if(arr[i]!=arr[i-1]){
			if(m>=s[i]*(i-1)) m-=s[i]*(i-1);
			else{
				cout<<i-1;
				return 0;
			}
		}
		else continue;
	}
	cout<<n;
	return 0;
}
