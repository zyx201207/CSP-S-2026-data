#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[1145141*5],s[1145141*5];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i]; 
	} 
	int ans=0;
	int j=0;
	for(int i=1;i<=n;i++){
		if(a[i]*(i-1-j)-s[i-1]+s[j]<=m){
			ans=max(ans,i-j);
//			cout<<i<<' '<<ans<< endl;
		}else{
			while(a[i]*(i-1-j)-s[i-1]+s[j]>m){
				j++;
			}
		}
	} 
	cout<<ans;
}//I love cyq
