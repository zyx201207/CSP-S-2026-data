#include<bits/stdc++.h>
using namespace std;
long long a[1000001],n,m,ws,x=1,sum=0,h=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(x<=a[n]){
		x*=2;
	}
	x/=2;
	while(x!=0){
		for(int i=n;i>=1;i--){
			if(a[i]>=x){
				h++;
			}
			if(a[i]==-1){
				break;
			}
		}
		if(h>=m){
			sum+=x;
			for(int i=n;i>=1;i--){
			if(a[i]>=x){
				a[i]-=x;
			}
			else{
				a[i]=-1;
			}
		}
		}
		else{
		for(int i=n;i>=1;i--){
			if(a[i]>=x){
				a[i]-=x;
			}
			else{
				break;
			}
		}	
		}
		sort(a+1,a+n+1);
		h=0;
		x/=2;
	}
	cout<<sum;
	return 0;
}
