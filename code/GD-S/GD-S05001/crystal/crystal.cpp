#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010],c[100010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long minn=INT_MAX,mint=-1;
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
		if(minn>c[i]){
			minn=c[i];
			mint=i;
		}		
	}
	long long l=mint,r=mint+1;
	long long ans=1;
	while(1){
		bool flag=0;
		if(l>1&&r<=n){
			if(c[l]<=c[r]*(r-l)){
				if(m-c[l]>=0){
					m-=c[l];
					ans++;
					c[l-1]+=c[l];
					c[l]=0;
					l--;
					flag=1;
				}
			}else{
				m-=c[r]*(r-l);
				ans++;
				c[l]+=c[r];
				r++;
				flag=1;
			}
		}else if(r<=n){
			if(m-c[r]*(r-l)>=0){	
				m-=c[r]*(r-l);
				ans++;
				c[r]=0;
				c[l]+=c[r];
				r++;
				flag=1;
			}				
		}else if(l>1){
			if(m-c[l]>=0){
				m-=c[l];
				ans++;
				c[l-1]+=c[l];
				c[l]=0;
				l--;
				flag=1;
			}
		}
		if(flag==0)break;
	}
	cout<<ans;
	return 0;
} 
