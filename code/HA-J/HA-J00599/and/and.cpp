#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=-1e9;
void sc30(){
	if(m==n){
		for(int i=1;i<=n;i++){
			if(i==1) ans=a[i];
			else ans&=a[i];
		}
		cout << ans;
		return;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
		return;
	}
	else{
		sort(a+1,a+n+1);
		if(m==1) cout << a[n];
		else cout << a[n-m+1];
		return;
	}
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sc30();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
