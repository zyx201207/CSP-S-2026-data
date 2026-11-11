#include<bits/stdc++.h>
using namespace std;
long n,m,a[200000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	int t;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[j]>a[j+1]){
				t=a[j+1];
				a[j+1]=a[j];
				a[j]=t;
			}
		}
	}
	int ans=0;
	for(int i=n-1;i>n-m;i--) ans=a[i]&a[i+1];
	cout<<ans;
	return 0;
}
