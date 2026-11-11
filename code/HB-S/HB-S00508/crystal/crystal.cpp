#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[10005],ans=0,sum=0,p=0,w=10000,s=0,d=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++){
cin>>a[i];

}
for(int i=1;i<=n;i++){
	sum+=a[i];
	p=sum/n;
	if(p>0){
	w=min(abs(a[i]-p),w);
	break;
	}s=i+1;
}
for(int i=1;i<=n;i++){
	if(abs(a[i]-a[s])<=m){
		if(a[i]>a[s]){
		while(a[i]!=a[s] and m>=0){
			a[s]++;
			m--;
			if(a[i]==a[s]){
				ans++;
				}
			}
		}
		else if (a[i]<a[s]){
		while(a[i]!=a[s] and m>=0){
			a[s]--;
			m--;
			if(a[i]==a[s]){
				ans++;
				}
			}
		}
		else {
			ans++;
			}
}
}
cout<<ans;
return 0;
}
