#include <bits/stdc++.h>
using namespace std;
long long steps;
int n;
long long a[500005];
int howmany(int basis,int place,int steps){
	if(place==1)return 0;
	if(basis-a[place-1]>steps)return 0;
	return 1+howmany(basis,place-1,steps-basis+a[place-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>steps;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	long long ans=0;
	for(int i=2;i<=n;i++){
		ans=max(ans,howmany(a[i],i,steps));
	}
	cout<<ans+1;
	return 0;
}
