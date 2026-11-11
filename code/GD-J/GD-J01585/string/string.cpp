#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
struct node{
	ll lar;
	char w;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n=0;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i].lar>>a[i].w;
	}
	ll ans=0;
	ll j=n;
	for(ll i=1;i<=n && i<=j;i++){
		if(a[j].lar==0)j--;
		if(a[i].lar<=a[j].lar){
			if(a[i].w==a[j].w){
				a[j].lar-=a[i].lar;
				a[i].lar=0;
			}
			else{
				ans+=a[i].lar;
				a[j].lar-=a[i].lar;
				a[i].lar=0; 
			}
		}
		else{
			do{
				if(a[i].w==a[j].w)	{
					a[i].lar-=a[j].lar;
					a[j].lar=0;
				}
				else {
					ans+=a[j].lar;
					a[i].lar-=a[j].lar;
					a[j].lar=0;
				}
			}while(a[i].lar>0 && a[j].lar<=0 && --j>=i);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

