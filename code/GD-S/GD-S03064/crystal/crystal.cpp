#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],maxn=0,ant;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==i){
			ant++;
		}
	}
	if (ant==n){
		long long z=0,ans=0,c=0;
		while (ans<=m){
			if (ans==m){
				cout<<c;
				return 0;
			}
			else {
				ans+=z;
				z++;
				c+=1;
			}
		}
	}
	sort(a+1,a+1+n);
	for (long long i=1;i<=n;i++){
		long long sum=0;
		for (int j=i-1;j>=1;j--){
			sum+=(a[i]-a[j]); 
		}
		if (sum<=m){
			maxn=i;
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
