#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
ll a[N],sum;
map<int,int>mp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i<=n;i++){
		if(mp[a[i]]>1){
			sum=a[i];
			m-=mp[a[i]];	
			if(m<=0){
				cout<<sum;
				return 0;
			}
		}
	}
	if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]+1==pow(2,j)||a[i]-1==pow(2,j)){
					sum=a[i];
					m--;
					if(m==0){
						cout<<sum;
						return 0;
					}
			}
		}
	}
	
	
	return 0;
}
