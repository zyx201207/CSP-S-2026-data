#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool cmp(int a,int b){
	return a>b;
}
int main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxx=0;
		for(int i=0;i<n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
	}
	else if(m==n){
		int ans=a[0];
		for(int i=1;i<n;i++){
			ans=a[i]&a[i]-1;
		}
		cout<<ans;
	}
	else if(m==2){
		int maxx=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i!=j){
					maxx=max(maxx,a[i]&a[j]);
				}
			}
		}
		cout<<maxx;
	}
	else{
		sort(a,a+n,cmp);
		cout<<a[m-1];
	}

	return 0;
}
