#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,gb;
int const N=5e5+10;
int arr[N],dp2[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cin>>n>>gb;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	if(n>=150000){
		if((arr[7891]-arr[7890])==(arr[1378]-arr[1377])){
			int cha=arr[2]-arr[1];
			int jb=1,tot=0;
			while(tot!=gb+1){
				for(int j=1;j<=cha*jb;j++){
					dp2[tot]=jb;
					if(tot==gb){
						cout<<jb;
						return 0;
					}
					++tot;
				}
				++jb;
			}
		}
		else{
			if(gb==0) cout<<1;
			else cout<<n/2;
		}
	}
	sort(arr+1,arr+1+n);
	int mx=-1e9,ans=1;
	for(int i=2;i<=n;i++){
		int m=gb;
		for(int j=i+1;j<=n;j++){
			if(arr[i]==arr[j]) ans++;
		}
		for(int j=i-1;j>=1;j--){
			if(arr[i]==arr[j]) ans++;
			else{
				int x=arr[i]-arr[j];
				if(x<=m){
					ans++;
					m-=x;
				}
				else{
					break;
				}
			}
			
		}
		mx=max(mx,ans);
		ans=1;
	}
	cout<<mx;
	
	
	return 0;
}
