#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ll n,m,s;
ll a[500005],b[500005],c[500005],h;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		h=0;
		memset(b,0,sizeof(b));
		for(int j=i+1;j<=n;j++){
			h++;
			b[h]=a[j];
			for(int l=1;l<h;l++){
				if(b[l]==b[h]){
					h=l;
					break;
				}
			}
		}
		for(int j=1;j<=h;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
