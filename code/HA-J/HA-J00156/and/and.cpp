#include<bits/stdc++.h>
using namespace std;
int a[20005],n,k;
int main(){
	//c1.length()
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}else if(k==2){
		int ra,rb;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(i==j)continue;
				if(ra&&rb<a[i]&&a[j])ra=a[i],rb=a[j];
			}
		
		}
		cout<<ra&&rb;
		return 0;
	}else if(n==k){
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];	
		}
		for(int i=2;i<n;i++){
			ans=a[1];
			ans=(ans&&a[i+1]);
		}
		cout<<ans;
		return 0;
	}else if(n==k+1){
		const int aaa=n;
		int ans2,ansr=0,ans1[aaa+1];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		
		for(int k=1;k<=n;k++){ans2=a[k];
			for(int i=1;i<=n;i++){
				if(i==k)continue;
				ans1[k]=ans2&&a[i];
				ans2=ans1[k];	
			}
			
		}
		for(int i=1;i<n;i++){
			if(ans1[i]>ansr)ansr=ans1[i];
			
		}
		cout<<ansr;
			
		return 0;
	}
	cout<<0;
	return 0;
} 
