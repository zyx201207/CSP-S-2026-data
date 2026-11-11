#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int mx=0;
	int n,m;
	cin>>n>>m;
	
	int  a[200010];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==3){
		for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
		for(int k=j+1;k<=n;k++){
			mx=max(mx,((a[i]&a[j])&a[k]));
		}
		}
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mx=max(mx,(a[i]&a[j]));
		}
	}
	
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[1];
		return 0;
	}
	cout<<mx;
	return 0;
}
