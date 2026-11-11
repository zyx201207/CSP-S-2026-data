#include<bits/stdc++.h>
using namespace std ;
const int maxn=500090;
long long n,m,a[maxn],c[maxn],ans=0;
bool fa=1,fb=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int d=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]!=i+1) fa=0;
		if(i>1){
			if(a[i]-a[i-1]!=d){
				fb=0;
			}
		}
		if(i==1){
			d=a[i]-a[i-1];
		}
	}
	if(fa==1){
		
		int i=0,cnt=0;
		for(;cnt+i<=m;i++){
			cnt+=i;
		}
		cout<<i;
		return 0;
	}
	if(fb==1){
		int i=0,cnt=0;
		for(;cnt+i<=m;){
			i++;
			cnt+=i*d;
		}
		cout<<i;
		return 0;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(i>0){
			c[i]=a[i]-a[i-1];
		}
	}
	
	for(int i=0;i<n;i++){
		int cnt=0;
		for(int j=i+1;j<n;j++){
			if(cnt+c[j]*(j-i)<m) cnt+=c[j]*(j-i);
			else if(cnt+c[j]*(j-i)==m){
				break;
			}else{
				j--;break;
			}
			ans=max(ans,(long long)j-i+1);
		}
	}
	cout<<ans;
	return 0;
	
}
