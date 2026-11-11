#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N],sum[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
			
		}
		cout<<ans;
		return 0;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	
	if(n<=31){
		int k=1<<n,ans=0;
		for(int i=1;i<k;i++){
			int num,count=0;
			bool check=true;
			for(int j=0;j<n;j++){
				if(((i>>j)&1)==1){
					count++;
					if(check){
						num=a[j+1];
						check=false;
					}else{
						num&=a[j+1];
					}
					
				}
			}
			if(count==m) ans=max(ans,num);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
