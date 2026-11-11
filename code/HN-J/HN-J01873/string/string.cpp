#include<bits/stdc++.h>
using namespace std;
struct ss{
	int num;
	char le;
}a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n;cin>>n;int maxa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].le;
		maxa=max(a[i].num,maxa);
	}
	if(maxa==1){
		char c[200005];
		for(int i=1;i<=n;i++){
			a[i].le=c[i];
		}
		int ans=0;
		for(int i=1,j=n;i<=j;i++,j--){
			if(c[i]!=c[j])ans++;
		}
		cout<<ans;
		return 0;
	}
		
		long long sum=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].num;j++){
				c[sum+j]=a[i].le;
			}
			sum+=a[i].num;
		}long long ans=0;
		for(int i=1,j=sum;i<=j;i++,j--){
			if(c[i]!=c[j])ans++;
		} 
		cout<<ans;
	
	return 0;
}

