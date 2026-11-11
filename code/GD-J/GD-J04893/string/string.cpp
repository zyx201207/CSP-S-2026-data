#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;cin>>n;
	long long a[200010],ans=0,num=0;
	char b[200010];
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];num+=a[i];
	}long long i=1,j=n;
	while(i<j){
		if(a[i]>0&&a[j]>0){
			if(b[i]!=b[j]){
				ans+=min(a[i],a[j]);
			}
			if(a[i]>a[j]){
				long long minn=min(a[i],a[j]);
				a[i]-=minn;a[j]-=minn;
				num-=2*minn;
				j--;
			}
			else if(a[i]<a[j]){
				long long minn=min(a[i],a[j]);
				a[i]-=minn;a[j]-=minn;
				num-=2*minn;
				i++;
			}
			else {
				long long minn=min(a[i],a[j]);
				a[i]-=minn;a[j]-=minn;
				num-=2*minn;
				j--;i++;
			}
		}
		
	}
		
	cout<<ans;
	return 0;
} 
