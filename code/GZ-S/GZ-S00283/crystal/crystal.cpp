//李杜文谦 GZ-S00283 清镇市广大实验学校 
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N=5e5+15;
int n,m,s,ans;
int a[N];
bool A,B;

bool cmp(int a,int b){
	return a<b;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=A)A=true;
	}
	if(!A){
		for(int i=1;i<=m;){
			ans++;
			i+=i+1;
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	int p=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=p)B=true;
	}
	if(!B){
		for(int i=0;i<m;){
			i=i+p*ans;
			if(i<=m)ans++;
		}
		cout<<ans;
		return 0;
	}
	for(int i=n;i>1;i--){
		int cnt=1;
		s=m;
		for(int j=i-1;j>=1;j--){
			if(s>=a[i]-a[j]){
				cnt++;
				s=s-a[i]+a[j];
			}else{
				continue;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
