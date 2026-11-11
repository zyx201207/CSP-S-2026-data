#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	else if(m==n){
		for(int i=2;i<=n;i++){
			a[i]=a[i]&a[i-1];
		}
		cout<<a[n];
		return 0;
	}
	else if(m==2){
		for(int i=2;i<=n;i++){
			if((a[i]&a[i-1])>ans)ans=a[i]&a[i-1];
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=1;i<=m;i++){
			if(i==1)ans=a[i];
			else ans=ans&a[i];
		}
		cout<<ans;
	}
	return 0;
}
