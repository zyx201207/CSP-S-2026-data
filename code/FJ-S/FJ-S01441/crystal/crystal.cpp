#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(a[1]==a[n]){
		cout<<n;
		return 0;
	}
	for(int i=n;i>=1;i--){
		int num=0;
		for(int j=1;j<i;j++){
			num+=a[i]-a[j];
		}
		if(m>=num){
			cout<<i;
			return 0;
		}
	}
	cout<<0;
	return 0;
}

