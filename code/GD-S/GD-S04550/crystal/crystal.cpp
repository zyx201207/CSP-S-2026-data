#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long m,n,a[N],sum=0,q[N],head=1,tail=0,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[++tail]=i;
		sum+=a[i];
		while(head<=tail && a[i]*(tail-head+1)-sum>m){
			sum-=a[q[head]];
			head++;
		}
		ans=max(ans,tail-head+1);
	}
	cout<<ans;
	return 0;
} 
