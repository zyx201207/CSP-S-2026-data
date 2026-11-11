//GZ-J00136 遵义市第十二中学  李明博 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,arr[500005],ass[500005],maa[300000];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++)cin>>arr[i];
	for(ll i=0;i<n;i++){
		ll id=0;
		for(ll j=0;j<n;j++)ass[i]=0;
		for(ll j=i;j<n;j++){
			bool as=0;
			ll o=0;
			for(ll k=0;k<id;k++){
				if(ass[k]==arr[j]){
					as=1;
					o=k;
				}
			}
			if(as){
				for(ll k=o+1;k<=id;k++){
					ass[k]=0;
				}
				id=o+1;
			}
			else {
				ass[id++]=arr[j];
			}
		}
		for(ll j=1;j<=m;j++){
			int as=0;
			for(ll k=0;k<=id;k++){
				if(ass[k]==j)as=1;
			}
			maa[j]+=as;
		}
	}
	for(ll i=1;i<=m;i++)cout<<maa[i]<<" ";
	fclose(stdin);fclose(stdout);
	return 0;
}
