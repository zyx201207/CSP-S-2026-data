//GZ-S00189 ³Âè÷Ðù
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],ans=1,k;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		for(long long i=1;i<=n;i++){
			int s=m;
			k=1;
			for(long long j=i-1;j>0;j--){
				if(a[i]-a[j]>s) break;
				else{
					s-=(a[i]-a[j]);
					k++;
				}
			}
			ans=max(ans,k);
		
		}
	
	}
	else{
		int c=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(k+c*i<=m){
				k+=c*i;
				ans++;
			}
			else break;
		}
	}
	cout<<ans;
	return 0;
	
}
