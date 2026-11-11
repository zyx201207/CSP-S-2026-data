#include<bits/stdc++.h>
using namespace std;
int s[200005];
int a[200005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	s[1]=a[1];
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]&a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n){
		int ans=a[1];
		
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(a[i]&a[j],ans);
			}
		}
		ans=max(a[1]&a[n],ans);
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=n;i>=1;i++){
		ans=max(s[i]&s[abs(i-m)],ans);
	}
	cout<<ans;
	return 0;
}
