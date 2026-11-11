#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
string s[200010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n,cmp);
		cout<<a[0];
		return 0;
	}
	else if(m==2){
			int ans=0,sum=0,maxn=-99999;
			for(int i=0;i<n;i++){
				for(int j=i+1;j<n;j++){
					sum=a[i] & a[j];
					if(maxn<=sum){
						maxn=sum;
					}
				}
			}
			cout<<maxn;
			return 0;
		}
	else if(m==n){
			int ans=a[0];
			for(int i=1;i<n;i++){
				ans=ans & a[i];
			}
			cout<<ans;
			return 0;
		}
	else if(m==n-1){
		int ans=a[0],maxn=-99999;
			for(int i=1;i<n;i++){
				for(int j=1;j<n;j++){
					if(j==i){
						continue;
					}
					ans=ans & a[j];
				}
				if(maxn<=ans){
						maxn=ans;
					}
					ans=a[0];
			}
			cout<<maxn;
			return 0;
	}
	else{
		sort(a,a+n,cmp);
		int ans=a[0],maxn=-99999,jw=0,sum=0;
		for(int i=1;i<m;i++){
			for(int j=1;j<n;j++){
				sum=ans;
				sum=a[j] & sum;
				if(maxn<=sum){
					maxn=sum;
					jw=j;
				}
			}
			ans=maxn;
			a[jw]=0;
			maxn=-99999;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
