#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],ans=0,k;
bool f=0,flag=0,f1=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	k=m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=i){
			f=1;
		}
		if(i>=3 && a[i]-a[i-1]!=a[i-1]-a[i-2]){
			flag=1;
		}
		if(a[i]!=a[i-1] && i!=1){
			f1=1;
		}
	}
	sort(a+1,a+n+1);
	if(m==0){
		int sum=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				sum++;
			}else{
				ans=max(ans,sum);
				sum=1;
			}
		}
		ans=max(ans,sum);
		cout << ans;
		return 0;
	}
	if(f==0){
		int cishu=1;
		ans=1;
		while(1){
			m-=cishu;
			if(m<0){
				break;
			}else if(m==0){
				ans++;
				break;
			}
			ans++;
			cishu++;
		}
		cout << ans;
		return 0;
	}
	if(f1==0){
		cout << n;
		return 0;
	}
	if(flag==0){
		int sum=a[2]-a[1],cishu=a[2]-a[1];
		ans=1;
		while(1){
			m-=cishu;
			if(m<0){
				break;
			}else if(m==0){
				ans++;
				break;
			}
			ans++;
			cishu+=sum;
		}
		cout << ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		int sum=0,anss=1;
		for(int j=i-1;j>=1;j--){
			sum=a[i]-a[j];
			if(k-sum>=0){
				anss++;
				k-=sum;
			}
		}
		ans=max(ans,anss);
		k=m;
	}
	cout << ans;
	return 0;
}
