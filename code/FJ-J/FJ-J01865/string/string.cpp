#include <bits/stdc++.h>
using namespace std;
int mani(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a[100005];
	long long c[100005], z[100005];
	cin>>n;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		z[i*a[i]]=c[i*a[i]];
	}
	   
	for(int a=1;a<=n;a++){
		for(int j=n;j>=1;j--){
			if((j+a)==(1+n)/2 && z[a]!=z[j]){
				cnt++;
			}
		
		}
	}
	if(cnt!=0){
		cout<<cnt;
	}
	return 0;
}
