#include<bits/stdc++.h>
using namespace std;
int n,m,ans=-999999999;
int i;
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>n>>m;
int s1[n+1];
for(i=1;i<=n;i++){
	cin>>s1[i];
}

if(n==m){
	ans=s1[1];
	for(i=2;i<=n-1;i++)
		ans=ans&s1[i]&s1[i+1];
		cout<<ans;
}
if(m==1){
	sort(s1,s1+n);
	cout<<s1[n];
}
if(m==2){
	for(i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,s1[i]&s1[j]);
		}
	}
	cout<<ans<<endl;
}
	return 0;
}
