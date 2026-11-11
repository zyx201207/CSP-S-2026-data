#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,maxans=1;
long long a[500005]={};
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	while(m>0){
		sort(a,a+n+1);
		a[1]+=1;
		m-=1;
		for(long long i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				ans++;
			}
		}
		if(ans>maxans) maxans=ans;
		ans=1;
	}
	sort(a,a+n+1);
	cout<<maxans;
	return 0;
}
