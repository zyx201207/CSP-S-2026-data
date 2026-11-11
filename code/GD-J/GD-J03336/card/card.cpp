#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=3e5+5;
ll n,a[N],m,s[N],t[N],r,c[N];
bool cmp(ll l,ll r){
	return l>r;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(c[a[j]]!=0){
				int z=r;
				while(t[z]!=a[j]){
					c[t[z]]--;
					z--;
				}
				r=z;
			}
			else{
				r++;
				t[r]=a[j];
				c[a[j]]++;
			}
		}
		for(int i=1;i<=r;i++){
			s[t[i]]++;
			c[t[i]]--; 
			t[i]=0;
		}
		r=0;
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
    return 0;
}
