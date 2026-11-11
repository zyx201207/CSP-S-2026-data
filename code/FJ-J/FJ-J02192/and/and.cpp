#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
int f(int x,int y){
	return (x&y);
}
long long ans;
int mx=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	else if(m==n){
		ans=a[1];
		for(int i=1;i<=n-1;i++){
			ans+=f(ans,a[i+1]);
		}
		cout<<ans;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,f(a[i],a[j]));
			}
		}
		cout<<mx;
		return 0;
	}
	else if(m==3){
		for(int i=1;i<=n-2;i++){
			for(int j=i+1;j<=n-1;j++){
				for(int k=j+1;k<=n;k++){
					mx=max(mx,f(a[i],f(a[j],a[k])));
				}
			}
		}
		cout<<mx;
		return 0;
	}
	else{
		sort(a+1,a+1+n);
		cout<<a[n-m];
		return 0;
	}
	
	
	
	
	
	return 0;
}
