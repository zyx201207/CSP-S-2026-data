#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],l=1,r=2,ans,total;
long long counter;
unsigned long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	while(r<=n){
		if(a[r]!=a[r-1]){
			total=0;
			for(int i=l+1;i<=r;i++){
				total=total+(a[i]-a[i-1])*(r-i+1);
			}
		}
		if(m>=total){
			counter=r-l+1;
			if(counter>=ans){
				ans=counter;
			}
			r++;
		}else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
