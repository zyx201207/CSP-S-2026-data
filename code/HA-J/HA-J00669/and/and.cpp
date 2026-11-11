#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	int ans=0;
	if(m==1){
		cout<<a[1];
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==n-1){
		ans=a[1];
		for(int i=2;i<=n;i++){
			if(m!=0){
				ans&=a[i];
				m--;
			}else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=N&&n>2000){
		ans=a[1];
		for(int i=2;i<=n;i++){
			if(m!=0){
				ans&=a[i];
				m--;
			}else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	ans=a[1];
		for(int i=2;i<=n;i++){
			if(m!=0){
				ans&=a[i];
				m--;
			}else{
				break;
			}
		}
		cout<<ans;
	return 0;
}
