#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
long long k,cha[500005];
long long ans=1;
long long ma=-1,mi=1e18;
bool flag = true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i <= n;i++){
		cin >> a[i];
		ma = max(a[i],ma);
		mi = min(a[i],mi);
	}
	sort(a+1,a+n+1);
	for(int i=2;i <= n;i++){
		cha[i]=a[i]-a[i-1];
		if(i >= 3&&cha[i]!=cha[i-1]){
			flag = false;
		}
	}
	if(flag){
		k=a[n];
		while(m>0){
			for(int i=n-1;i >= 1;i--){
				if(m-(k-a[i]) >= 0){
					//cout<<k<<" "<<a[i]<<" ";
					m=m-k+a[i];
					if(ans >= n){
						cout<<ans;
						return 0;
					}
					ans++;
				}else{
					cout<<ans;
					return 0;
				}
			}
		}
		cout<<ans;
		return 0;
	} else{
		
		for(int i=mi;i <= ma;i++){
			long long mm=m;
			long long num=1;
			long long k=i;
			for(int j=2;j <= n;j++){
				if(mm - (j-1)*(a[j],a[j-1]) >= 0){
					mm -= (j-1)*(a[j],a[j-1]);
					if(num >= n){
						ans = max(num,ans);
						break;
					}
					num++;
				}else{
					ans = max(num,ans);
					break;
				}
				
			}
			ans = max(num,ans);
		}
		cout<<ans;
	}	
	return 0;
}
//5 5
//1 2 4 8 9
