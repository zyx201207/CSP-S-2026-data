#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m,tmpm,ans,res;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		long long d=a[2]-a[1];
		double tmp1=double(d);
		double tmp2=double(m);
		int ans0=int(floor(sqrt(tmp1*tmp1+8*tmp1*tmp2)-tmp1)/(2*d))+1;
		cout<<ans0;
		return 0;
	} 
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		tmpm=m;
		res=1;
		for(int j=i;j>=1;j--){
			if(m>=a[i]-a[j]){
				res++;
				m-=a[i]-a[j];
			}else{
				break;
			}
		}
		ans=max(ans,res);
	}
	printf("%lld",ans);
	return 0;
} 
