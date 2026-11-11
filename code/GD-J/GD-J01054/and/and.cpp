#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2*1e5+2;
ll a[N],n,m;
ll max1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1,greater<ll>());
		cout<<a[1];
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>max1){
					max1=a[i]&a[j];
				}
			}
		}
	}
	int x=a[2]&a[1];
	cout<<x;
	return 0;
}
