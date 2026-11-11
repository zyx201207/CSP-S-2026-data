#include<bits/stdc++.h>
#define ll long long
using namespace std;

	ll a[200010];
	char b[200010];
	ll n;
	ll ans=0,l,r;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(ll i=1;i<=n;i++)cin>>a[i]>>b[i];
	l=1,r=n;
	while(l<r){
		if(a[l]==0)l++;
		if(a[r]==0)r--;
		if(l>=r)break;
		if(b[l]==b[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]==a[r]){
				l++;
				r--;
			}
		}else if(a[l]>a[r]){
			a[l]-=a[r];
			ans+=a[r];
			r--;
		}else if(a[l]<a[r]){
			a[r]-=a[l];
			ans+=a[l];
			l++;
		}else if(a[l]==a[r]){
			ans+=a[r];
			r--;
			l++;
		}
	}
	cout<<ans<<" ";
	return 0;
}
//T2
//string
//夜晚的凉风吹过身边
//空荡的街上只剩想念 
//想念你天真无邪的笑颜 
//回头你却在在已经不见
//不堪的生活每天重演 
//这世界在意换了人间 
//路灯矗立街边依旧耀眼 
//照我的人生无奈的从前
//
//
//
// 
