#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],ans,qz[500005];
bool bj;
void xd(){
	//A:3tps 15score
	for(int i=1;i<=n;i++){
		qz[i]=qz[i-1]+a[i];
		if(qz[i]<=m&&i<n)ans=i+1;
	}
	cout<<ans;
}
void bl(){
	//bl:7pts 35score
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]>m)break;
		int c=0,j=i-1,l=1;
		while(j>0){
			if(c+(a[i]-a[j])<=m){
				l++;c+=a[i]-a[j];j--;
			}else{
				break;
			}
		}
		if(l>ans)ans=l;
	}
	cout<<ans;	
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)bj=1;
	}
	if(bj==0)xd();
	else bl();
	return 0;
}