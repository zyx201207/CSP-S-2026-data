#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int cnt=0,k=1;
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			cnt+=a[i]-a[j];	
		}
		if(cnt>m){
			break;
		}
		k=i;
		cnt=0;
	}
	cout<<k;  
	return 0;
} 
