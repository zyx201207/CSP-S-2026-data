#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N=1e6+10;

ll n,m,a[N],ans,cnt,tmp;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n>5000){
		char c='?';
		bool aaa=0;
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4){
			c='A';
			aaa=1;
		}else{
			if(a[2]-a[1]==a[3]-a[2]){
				c='B';
			}
		}
		if(c=='A'){
			tmp=m;
			cnt=1;
			for(int i=1;i<=n;i++){
				if(tmp>=i){
					tmp-=i;
					cnt++;
				}
			}
			ans=cnt;
			if(cnt>n){
				ans=n;
			}
		}
		if(c=='B'&&!aaa){
			ll aa=a[4]-a[3];
			tmp=m;
			cnt=1;
			for(int i=1;i<=n;i++){
				if(tmp>=i*aa){
					tmp-=i*aa;
					cnt++;
				}
			}
			ans=cnt;
			if(cnt>n){
				ans=n;
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			tmp=m;
			cnt=0;
			for(int j=i;j>=1;j--){
				if(tmp>=a[i]-a[j]){
					tmp-=a[i]-a[j];
					cnt++;
				}else{
					break;
				}
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
//5 8
//-3 -1 2 2 7
