#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,l=0;
ll a[500010],b[500010]={0},f;
ll res[300010];
struct Node{
	bool y;ll x;
}k[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			l++;
			if(k[a[j]].y){
				for(int c=k[a[j]].x+1;c<=l;c++){
					l=k[a[j]].x;
				}
				l=k[a[j]].x;
			}	
			b[l]=a[j];
			k[a[j]].y=1;
			k[a[j]].x=l;
		}
	for(int j=1;j<=l;j++){
		cout<<b[j]<<" ";
		res[b[j]]++;
	}
	cout<<endl;
	for(int j=1;j<=m;j++){
			k[j].y=0,k[j].x=0;
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<" ";
	}
		
}
