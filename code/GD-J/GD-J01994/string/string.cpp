#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2*1e5+5;
int n,a[N],pre,cur,ans,sum;
char c[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	sum/=2;
	int i=1,j=n;
	while(i<j){
		int b=min(sum-pre,a[i]);
		a[i]-=b;
		pre+=b;
		while(cur<pre){
			int d=min(pre-cur,a[j]);
			a[j]-=d;
			cur+=d;
			if(c[i]!=c[j])ans+=d;
			if(a[j]==0)j--;
		}
		i++;
	}
	cout<<ans;
	return 0;
}
