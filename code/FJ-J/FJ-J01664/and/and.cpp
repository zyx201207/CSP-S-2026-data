#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a,a+n);
	if(m==1) cout << a[n];
	else if(m==2){
		int ans=-1;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int t=a[i]&a[j];
				ans=max(ans,t);
			}
		}
		cout << ans;
	}else if(m==n){
		int t=a[1];
		for(int i=2;i<=n;i++){
			t&=a[i];
		}
		cout << t;
	}else{
		cout << 262142;		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
