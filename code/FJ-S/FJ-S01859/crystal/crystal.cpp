#include<bits/stdc++.h>
using namespace std;
int n,a[500005],ans,temp,maxn;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=25000){
		sort(a,a+n);
		for(int i=1;i<n;i++){
			ans=1;
			temp=0;
			for(int j=i-1;j>=0;j--){
				temp+=a[i]-a[j];
				if(temp<=m){
					ans++;
				}
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn;
	}else{
		int t=a[1]-a[0];
		bool at=true,bt=true;
		for(int i=0;i<n;i++){
			temp=a[i+1]-a[i];
			if(a[i]!=i+1){
				at=false;
			}else if(temp!=t){
				bt=false;
			}
		}
		ans=1;
		if(at){
			temp=0;
			for(int i=1;i<=1000000000000000000;i++){
				temp+=i;
				if(m<temp){
					cout<<i;
					return 0;
				}
			}
		}else if(bt){
			temp=0;
			int sum=0;
			for(int i=1;i<=1000000000000000000;i+=t){
				temp+=i;
				sum++;
				if(m<temp){
					cout<<sum;
					return 0;
				}
			}
		}
	}
	return 0;
} 
