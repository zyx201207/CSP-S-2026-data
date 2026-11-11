//GZ-S00147 杨俊毅 遵义市南白初级中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,d;
bool q=1;
long long a[500005];	
long long ans1=0,ans2=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long temp=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) q=0;
		temp+=a[i];
	}
	if(q){
		long long k;
			k=n/2+1;
		for(long long i=k;i>=1;i--){
				if(m>=a[k]-a[i]){
			m-=a[k]-a[i];
			ans2++;
		}else{
			break;
		}
		}
		cout<<ans2;
		return 0;
	}
	d=temp/n;
    sort(a+1,a+1+n);
    long long x,y;
		for(long long i=1;i<=n;i++){
       if(a[i]<=d) x=i; 
	} 
	for(long long i=x;i<=n;i++){
		if(a[i]>=d){
			if(a[i+1]==a[i]&&i!=n-1){
				continue;
			}else{
				y=i;
				break;
			}
		}
	} 
	if(d-a[x]<a[y]-d){
		ans1=x;
	}else if(d-a[x]>a[y]-d){
		ans1=y;
	}else if(d-a[x]==a[y]-d){
		ans1=y;
	}
	for(long long i=ans1;i>=1;i--){
		if(m>=a[ans1]-a[i]){
			m-=a[ans1]-a[i];
			ans2++;
		}else{
			break;
		}
	}
	cout<<ans2;
	return 0;
}
