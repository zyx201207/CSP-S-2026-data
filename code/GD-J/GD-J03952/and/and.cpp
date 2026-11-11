#include<bits/stdc++.h>
using namespace std;

long long a[200005],ans;
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout << a[1];
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout << ans;
		return 0;
	}
	else if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout << ans;
		return 0;
	}
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			long long temp=0b1111111111111111111111111111111;
			for(int j=1;j<=n;j++){
				if(j!=i) temp=(temp&a[j]);
			}
			ans=max(temp,ans);
		}
		cout << ans;
		return 0;
	}
	else{
		ans=a[1];
		for(int i=1;i<=m;i++){
			ans=(ans&a[i]);
		}
		cout << ans;
		return 0;
	}
	
	
	return 0;
}
 
