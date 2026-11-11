#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],s=1,b[500005],sum[300005];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		b[i]=a[i];
	}
	for(int i = s;i<=n;i++){
		for(int h=s;h<=n;h++){
			for(int j = h+1;j<=n;j++){
				if(a[h]==a[j]){
					for(int k = h;k<j;k++){
						a[k]=0;
					}
				}
			}
		}
		for(int k = s;k<=n;k++){
			if(a[k]!=0){
				sum[a[k]]++;
				
			}
		}
		s++;
		for(int k = s;k<=n;k++){
			a[k]=b[k];
		}
		
	}
	for(int i = 1;i<=m;i++){
		cout << sum[i] << " ";
	}
	return 0;	
} 
