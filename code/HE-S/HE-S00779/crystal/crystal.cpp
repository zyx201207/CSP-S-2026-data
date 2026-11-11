#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m,ans=1,ans1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	for(int i=0;i<n;i++){
		if(m==0){
			break;
		}
		a[0]+=1;
		m-=1;
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(a[i]>a[j]){
					int temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		}
		for(int j=1;j<n;j++){
			if(a[j-1]==a[j]){
				ans+=1;
			}
			if(ans>ans1){
				ans1=ans;
				ans=1;
			}
		}
	}
	cout<<ans1;
	return 0;
} 
