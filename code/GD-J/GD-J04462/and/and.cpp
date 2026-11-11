#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5,Log=log2(N)+1;
int n,m;
long long a[N];
int num[Log+5];
bool cmp(int x,int y){
	for(int i=Log;i>=1;i--){
		if(num[i]<m)continue;
		int j=(x>>i)&1,k=(y>>i)&1;
		if(j!=k){
			return j>k;
		}
	}
	int j=x&1,k=y&1;
	return j>k;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		int x=a[i],j=0;
		while(x){
			num[j]+=(x&1);
			j++;
			x/=2;
		}
	}
	sort(a+1,a+n+1,cmp);
	long long ans=a[1];
	for(int i=2;i<=m;i++)ans&=a[i];
	cout<<ans;
	return 0;
}
