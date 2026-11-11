#include<bits/stdc++.h>
using  namespace std;
int cmp(int a,int b){
	return a>b;
}
int n,m,a[200005],s[200005],cnt[200005],maxn,minn=10000,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	if(m==1){
		cout<<maxn;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		int t=a[i];
		while(t){
			t/=2;
			s[i]++;
		}
		minn=min(s[i],minn);
	}
	for(int i=1;i<=m;i++){
		while(a[i]){
			int t=a[i]%2;
			int k=1;
			if(t){
				cnt[k]++;
			}
			s[i]--;
			a[i]/=2;
			k++;
		}
	}
	for(int i=1;i<=minn;i++){
		if(cnt[i]==m){
			int t=pow(2,i-1);
			ans+=t;
		}
	}
	cout<<ans;
	return 0;
}
