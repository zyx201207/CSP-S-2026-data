#include<bits/stdc++.h>
using namespace std;
long long n;
long long m,a[5000005],maxx,c[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(int i = 2;i<=n;i++){
			long long j = i,k = m,ans = 1;
			while(j>=2){
				j--;
				if(a[i]-a[j]<= k){
					ans++;
					k-=abs(a[i]-a[j]);
				}else{
					break;
				}
				
			}
			maxx = max(maxx,ans);
			
		}
		cout<<maxx<<' ';		
	} else{
		for(int i = 2;i<=n;i++){
			c[i] = (a[i]-a[i-1])*(i-1)+c[i-1];
			if(c[i]>m){
				cout<<i-1;
				return 0;
			}
		}
		cout<<n;
	}

	
} 
