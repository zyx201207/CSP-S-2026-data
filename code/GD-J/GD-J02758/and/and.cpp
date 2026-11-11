#include <bits/stdc++.h>
using namespace std;
const int mx=200005;
int n,m;
int a[mx];
bool b[mx];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}else if(m==2){
		int ans=a[1]&a[2];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	int ans=a[n];
	for(int i=2;i<=m;i++){
		int val_mx=ans,id=0;
		int t=0;
		for(int j=1;j<=n;j++){
			if(!b[j]){
				if(val_mx&a[j]>=t){
					t=val_mx&a[j];
					id=j;
				}
			}
		}
		ans=t,b[id]=true;
	}
	cout<<ans;
	return 0;
}
