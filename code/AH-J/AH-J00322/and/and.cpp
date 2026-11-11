#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		int mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int t=a[i]&a[j];
				mx=max(mx,t);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		int h=a[1];
		for(int i=2;i<=n;i++){
			h=h&a[i];
		}
		cout<<h;
		return 0;
	}
	return 0;
}
