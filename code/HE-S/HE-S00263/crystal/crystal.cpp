#include<bits/stdc++.h> 
using namespace std;
long long n,m,o,mx=INT_MIN,sum=0;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	o=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum=0;
		m=o;
		for(int j=i;j>=1;j--){
			if(m>=a[i]-a[j]){
				m-=(a[i]-a[j]);
				sum++;
			}else{
				break;
			}
		}mx=max(mx,sum);
	}cout<<mx;
}
