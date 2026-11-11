#include<bits/stdc++.h>
#define int long long
using namespace std;
int sum,r,l,n,ans[1000001],k,x,y;
bool p;
struct tt{
	int n;
	char s;
}a[1000001];
main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].n);
		cin>>a[i].s;
		ans[i]=ans[i-1]+a[i].n; 
	}
	if(ans[n]%2==1) k=ans[n]/2+1,p=0;
	else k=ans[n]/2,p=1;
	
	for(int i=1;i<=n;i++){				
		if(ans[i-1]+1<=k&&ans[i]>=k&&p==0){
			x=ans[i]-k;
			y=k-ans[i-1]-1;
			if(p==1) y++;						
			a[i].n=a[i].n-min(x,y)*2-1;
			if(p==1) a[i].n++;			
			break;
		}		
	}		
	r=1,l=n;
	while(l-r>0){
		if(a[r].n==0){
			r++;
			continue;
		}
		if(a[l].n==0){
			l--;
			continue;
		}
		if(l-r<0) break;
		if(a[r].s==a[l].s){
			if(a[r].n>a[l].n){
				a[r].n-=-a[l].n;
				l--;
			}
			else{
				a[l].n-=a[r].n;
				r++;
			}
		}
		else{
			if(a[r].n>a[l].n){
				sum+=a[l].n;
				a[r].n-=a[l].n;
				l--;
			}
			else{
				sum+=a[r].n;
				a[l].n-=a[r].n;
				r++;
			}
		}
	}
	cout<<sum;
}
