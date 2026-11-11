#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long gg=0,ans=0,k=0,j=0,cnt=0;
	for(long long i=1;i<=n;i++){
		j=i;
		cnt=0;
		while(true){
			if(j>n){
				break;
			}
			k=(j-i)*(a[j]-a[j-1]);
			cnt=cnt+k;
			if(m<cnt){
				break;
			}
			j++;
			ans++;
			
		}
		gg=max(ans,gg);
		ans=0;
	}
	cout<<gg;
	
	return 0;
}
