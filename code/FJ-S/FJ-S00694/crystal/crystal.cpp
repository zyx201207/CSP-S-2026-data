#include<bits/stdc++.h>
using namespace std;
long long n,a[500005];
unsigned long long sum,m,ans,head=1,lj=1,dc=1,c;
int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2){
			 c=a[i]-a[i-1];
		}if(i>2){
			if(a[i]-a[i-1]!=c){
				dc=0;
			}
		}
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-lj);
		while(sum>m){
			ans=max(ans,i-lj);
			sum-=a[i]-a[head];
			lj++;head++;
			if(dc==1){
				cout<<ans;
				return 0;
			}
		}
		
	}if(head==1){
		cout<<n;
	}else cout<<ans;
	return 0;
} 
