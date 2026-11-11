#include<bits/stdc++.h>
using namespace std;
long long a[200010],k[200010],j;
long long ans;
int n,m,s,f;
int c(long long shu){
	long long MAXN=(1<<30);
	long long minn=1LL;
	while(MAXN!=2){
		minn=min(minn,MAXN-shu);
		MAXN/=2;
	}
	return minn;
}
int check(){
	long long b[200010];
	for(int i=0;i<n;i++){
		b[i]=a[i];
	}
	long long cnt=1LL;
	for(int i=n-1;i>=0;i--){
		if(b[i]!=0){
			if(c(b[i])<cnt){
				cnt=c(b[i]);
				ans=b[i];
				f=i;
			}else{
				if(ans<b[i]){
					f=i;
					ans=b[i];
				}
			}
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		k[j++]=check();
		a[f]=0;
		//for(int j=0;j<n;j++)cout<<a[j]<<' ';
		//cout<<endl<<k[j-1]<<' ';
	}
	ans=k[0];
	for(int i=1;i<j;i++){
		ans=k[i]&ans;
	}
	cout<<ans;
	return 0;
}

