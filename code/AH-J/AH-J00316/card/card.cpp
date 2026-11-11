#include<bits/stdc++.h>
using namespace std;
int m,n,a[500005],t[300005],pz[500005],st,ed;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		for(int st=i,ed=1;st<n;st++){
			bool c=0;
			for(int j=1;j<ed;j++){
				if(pz[j]==a[st]){
					ed=j;
					c=1;
					break;
				}
			}
			if(!c){
				pz[ed]=a[st];
				ed++;
			}
		}
		for(int j=1;j<ed;j++){
			t[pz[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
			cout<<t[i]<<" ";
	}
	return 0;
}
