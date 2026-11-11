#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,max1=0;
long long a[10010];
long long s,c;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=n;i>1;i--){
		for(long long j=i;j>=1;j--){
			if(a[i]>=a[j])
			ans+=a[i]-a[j];
			if(ans<=m){
				if(max1<ans){
					max1=ans;
					s=i;
					c=j;
				}
			}
		}
		ans=0;
	}
	cout<<s-c+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
