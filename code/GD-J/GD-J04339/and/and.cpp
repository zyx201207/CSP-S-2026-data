#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=2e5+7;
int n,m,a[N],ans,ma;

int ct(int x){
	int cnt=0;
	while(x){
		cnt+=(x&1);
		x/=2;
	}
	return cnt;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<(1<<n);i++){
		if(ct(i)!=m) continue;
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				int tot=a[j];
				if(cnt==0) cnt=tot;
				else cnt&=tot;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
