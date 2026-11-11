#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ma=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long l=i,r=i,t=m;
		while(t>=0){
			if(l==1 && r==n){
				break;
			}else if(l==1 && r!=n){
				while(r+1<=n && a[r+1]-a[i]<=t){
					r++;
					t-=(a[r]-a[i]);
				}
			}else if(l!=1 && r==n){
				while(l-1>=1 && a[i]-a[l-1]<=t){
					l--;
					t-=(a[i]-a[l]);
				}
			}else if(l-1>=1 && a[i]-a[l-1]<a[r+1]-a[i] && a[i]-a[l-1]>=t){
				l--;
				t-=(a[i]-a[l]);
			}else if(r+1<=n && a[i]-a[l-1]>a[r+1]-a[i] && a[r+1]-a[i]>=t){
				r++;
				t-=(a[r]-a[i]);
			}else{
				break;
			}
		}
		ma=max(ma,r-l+1);		
	}
	cout<<ma;
	return 0;
}
