#include <bits/stdc++.h>
using namespace std;
int a[10005];int n,m;
int cnt=0;
int ans=0;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
	cin>>a[i];
}
for(int i=0;i<n;i++){
	int j=i+1;
	while(m--){
		cnt=a[i]&a[j];
		if(m==0){
			ans=max(ans,cnt);
		}
	}
}
cout<<ans;
return 0;	
}
