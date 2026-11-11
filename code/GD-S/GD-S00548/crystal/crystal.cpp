#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	long long maxa=0;
	long long bz=0,ii=0,sum=0;
	for(int i=0;i<n;i++){
		if(i&&a[i]==a[i-1]) sum++;
		else sum=1; 
		if(sum>maxa){
			maxa=sum;
			bz=a[i];
			ii=i-sum+1;
		}
	}
	int l=0,r=n-1;
	if(maxa==1){
		ii=l+(r-l)/2;
		bz=a[ii];
	}
	int jj=ii+1;
	long long ans=0;
	while((ii>=0||jj<=n-1)&&m>0){
		int x=abs(a[ii]-bz),y=abs(a[jj]-bz);
		if(m-y<0&&m-x<0) break;
		if(x==0){
			ans++,ii--;
		}
		else if(y==0){
			ans++,jj++;
		}
		else if((x<=y||m-y<=0)&&m-x>=0){
			if(m<=0||m-x<0){
				break;
			}
			ans++;
			m-=x;
			ii--;
		}
		else if((x>y||m-x<=0)&&m-y>=0){
			if(m<=0||m-y<0){
				break;
			}
			ans++;
			m-=y;
			jj++;
		}
	}
	cout<<ans;
	return 0;
} 
