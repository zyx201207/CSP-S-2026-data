#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans1,ans2,t[3000010],p=1,ans;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		ans1=max(ans1,a[i]);
		if(i==1)ans2=a[i];
		if(a[i]>3000000)p=0;
		if(a[i]<=3000000){
			t[a[i]]++;
		}
	}
	if(m==1){
		cout<<ans1;
		return 0;
	}
	if(m==n){
		cout<<ans2;
		return 0;
	}
	long long ans3=0;
	if(p==1){
		if(t[ans1]>=m){
			cout<<ans1;
			return 0;
		}
		for(int i=1;i<=n;i++){
			if(t[a[i]]>=m){
				ans3=max(ans3,a[i]);
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	ans=max(ans3,ans);
	ans3=a[1];
	int k=1;
	while(ans3%2==0){
		k++;
		ans3=a[k];
	}
	int x=m-1;
	for(int i=k+1;i<=n;i++){
		if(x==0)break;
		else if(a[i]%2==1){
			ans3&=a[i];
		}
	}
	ans3=max(ans,ans3);
	ans=a[1];
	k=1;
	while(ans%2==1){
		k++;
		ans=a[k];
	}
	x=m-1;
	for(int i=k+1;i<=n;i++){
		if(x==0)break;
		else if(a[i]%2==0){
			ans&=a[i];
		}
	}
	ans=max(ans,ans3);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
