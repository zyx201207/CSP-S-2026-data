#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],ans;
bool iAf=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) iAf=false;
	}
	if(iAf){
		int mid=n/2+1;
		int l=mid-1,r=mid+1;
		while(m){
			if(m-(a[mid]-a[l])>=0){
				m-=(a[mid]-a[l]);
				ans++;
				l--;
			}else if(m-(a[r]-a[mid]>=0)){
				m-=(a[r]-a[mid]);
				ans++;
				r++;
			} else{
				cout<<ans;
				return 0;
			}
		}
	}
	return 0;
}
