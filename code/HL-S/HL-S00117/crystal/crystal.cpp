
#include<bits/stdc++.h>
using namespace std;
int n;
long long m,sum;
int ans=0;
int a[1000005];
int b[1000005];

int main(){
	freopen("crystal .in","r",stdin);
	freopen("crystal .out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]==a[n]){
		cout<<m; 
		return 0;
	}
	int mid=a[(n+1)/2];
	for(int i=1;i<=n/2;i++){
		if(mid-a[i]<=m){
			ans++;
			m-=(mid-a[i]);
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==mid){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
