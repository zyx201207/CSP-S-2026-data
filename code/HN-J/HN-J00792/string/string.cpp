#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans;
struct node{
	long long sum;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i].sum>>a[i].c;
	long long tot=n,i=1;
	while(i<=tot){
		if(a[i].sum>=a[tot].sum){
			if(a[i].c==a[tot].c){
				a[i].sum-=a[tot].sum;
				tot--;
			}else{
				ans+=a[tot].sum;
				a[i].sum-=a[tot].sum;
				tot--;
			}
		}else{
			if(a[i].c==a[tot].c){
				a[tot].sum-=a[i].sum;
				i++;
			}else{
				ans+=a[i].sum;
				a[tot].sum-=a[i].sum;
				i++;
			}
		}
		if(a[i].sum==0) i++;
		if(a[tot].sum==0) tot--;
	}
	cout<<ans;
	return 0;
}
