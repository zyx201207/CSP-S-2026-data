#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e9+100;
int a[MAXN];
int m,n;
int ans,reinonum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	reinonum=a[n/2];
	for(int i=1;i<=m;i++){
		if(a[1]<reinonum){
			a[1]++;
			if(a[1]>a[2]){
				int kawari=a[2];
				a[2]=a[1];
				a[1]=kawari;
			} 
		}
		if(a[1]==reinonum){
			ans++;
			if(a[1]==a[2]){
				ans--;
				break;
			}
		}
		}
	cout<<ans;
	return 0;
} 
