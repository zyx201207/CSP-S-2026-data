#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum=0,cnt=0,mid;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
			if(n%2==1){
				mid=(n+1)/2;
			}
			else{
				mid=n/2;
			}
			for(int i=1;i<=mid;i++){
				cnt+=mid-a[i];
				if(cnt>m){
					continue;
				}
				else{
					a[i]+=mid-a[i];
					if(a[i]<0){
						a[i]-=mid-a[i];
					}
				}
			}
		}
	for(int i=1;i<=n;i++){
		if(a[i]==mid){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
