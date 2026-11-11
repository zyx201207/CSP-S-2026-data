#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,m,a[N],ans,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				sum=a[i]&a[j];
			}
			ans=max(ans,sum);
		}
		cout<<sum;
		return 0;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=j;k<=j;k++){
					sum=a[i]&a[j]&a[k];
				}
				ans=max(ans,sum);
			}
		}
		cout<<sum;
		return 0;
	}
	cout<<1;
	return 0;
}
