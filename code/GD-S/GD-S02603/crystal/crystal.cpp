#include<bits/stdc++.h>

using namespace std;

using ll=long long;

using db=double;

#define int ll

#define endl '\n'

const int N = 5e5+8;
int n,m;
int a[N],cha[N],qianz[N];

void solve(){
	cin>>n>>m;
	int mm=m,ch;
	bool ok=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1){
			if(i==2) ch=a[i]-a[i-1];
			else{
				if(ch!=a[i]-a[i-1]){
					ok=0;
				}
			}
		}
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		qianz[i]=qianz[i-1]+cha[i];
	}
	if(n<=5000){
		int ans=0;
		for(int i=1;i<=n;i++){
			m=mm;
			for(int j=i+1;j<=n;j++){
				if(m-(a[j]-a[j-1])*(j-i)<0) break;
				m-=(a[j]-a[j-1])*(j-i);
				ans=max(ans,j-i+1);
			}
		}
		cout<<ans;
	}else if(ok){
		int ans=0;
		int l=0,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(((1+mid)*mid)/2<=m){
				ans=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		cout<<ans;
	}else{
		
	}
	return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	solve();
	return 0;
}



