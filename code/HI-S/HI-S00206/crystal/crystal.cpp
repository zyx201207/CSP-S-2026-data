#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000010];
int check(int k){
	int sum=0;
	long long d[10000];
	int y=0;
	for(int i=1;i<=n;i++){
			if(a[i]<=k){
				d[i]=k-a[i];
				y++;
			}
		}
	sort(d+1,d+y+1);
	for(int i=1;i<=y;i++){
		sum+=d[i];
	}		
		return sum;	
	}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=a[1],r=a[n];
	int ans=1;
	while(l<=r){
		int mid=(l+r)/2;
		int win=check(mid);
		if(win==m){
			int c=0;
			for(int i=1;i<=n;i++){
				if(a[i]<=mid){
					c++;
				}
				else{
					break;
				}
			}
					ans=c;
					break;		
		}
		if(win>m){
			r=mid-1;
		}
		else{
			l=mid+1;
		}
		
	}
	cout<<ans;
	return 0; 
}
