#include<bits/stdc++.h>
using namespace std; 
int m,n,k[200005],maxn=-1,ad[77]; 
bool f(int x1,int x2){
	return x1>x2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>k[i];
	}
	sort(k+1,k+1+m,f);
	int ans=k[1];
	for(int i=1;i<=n;i++){
		ans&=k[i];
	}ad[1]=ans;
	ans=k[2];
	
	for(int i=2;i<=n+1;i++){
		ans&=k[i];
	}ad[2]=ans;
	ans=k[3];
	
	for(int i=3;i<=n+2;i++){
		ans&=k[i];
	}ad[3]=ans;
	ans=0;
	
	ad[4]=k[1]&k[3]&k[4];
	ad[5]=k[1]&k[2]&k[4]; 
	ad[6]=k[2]&k[3]&k[5];
	ad[7]=k[2]&k[4]&k[5];
	
	cout<<max(max(max(max(ad[1],ad[4]),max(ad[2],ad[3])),)max((max(ad[5],ad[6]),ad[7])));
	
	return 0;
}
