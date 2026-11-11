#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[20010];
int maxx=INT_MIN;
int maxx2=INT_MIN;
int cnt,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt=a[1];
		if(a[i]>maxx){
			maxx=a[i];
		}
		cnt=cnt&a[i];
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(maxx2,a[i]&a[j]);				
			}
		}
	}else if(m==n){
		cout<<cnt;
		return 0;
	}
	cout<<ans;
	return 0;
}
