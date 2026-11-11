#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ind=1;
	while(m>0){
		while(a[ind+1]==a[ind]) ind++;
		if(a[ind+1]-a[ind]>m){
			break;
		}
		else{
			long long num=min(m/(a[ind+1]-a[ind]),ind);
			m-=(a[ind+1]-a[ind])*num; 
			long long cnt=0,ind2=ind;
			while(num>0 && ind2>=1){
				a[ind2]=a[ind+1];
				num--;
				ind2--;
			}
			for(long long i=1;i<=n;i++){
				if(a[i]==a[ind+1]){
					cnt++;
				}
			}
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
