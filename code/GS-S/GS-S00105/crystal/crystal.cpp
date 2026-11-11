#include<bits/stdc++.h>
using namespace std;
const long long N=1e8;
long long n,m,a[N];
int sum=0,ans=0,x=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		a[x]=a[n/2];
		if(m>=0){
			if(a[ans]<a[x]) {
				a[ans]++;
				m--;
			}	
			if(a[ans]==a[x]){
				sum++;
				ans++;
			} 
		}
	}
	cout<<sum<<endl;
	return 0;
}
