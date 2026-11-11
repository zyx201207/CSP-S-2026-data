//GZ-J00200 观山湖中学 马志翔  
#include<bits/stdc++.h>
using namespace std;
void ji(){
	long long n,m;
	cin>>n>>m;
	vector<long long>a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long ans=0,maxn=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			maxn=max(maxn,a[i]&a[i-1]);
		}
	}
	cout<<maxn<<endl;
	return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int t=1;
    //cin>>t;
	while(t--){
		ji();
	} 
	return 0;
}
