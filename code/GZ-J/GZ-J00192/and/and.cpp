//GZ-J00192ÕÅ½ÜÈð 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200886],ans=LLONG_MAX;bool b[46];
bool cmp(long long a,long long b){return a>b;}
void bin(long long n){
	for(int i=0;n;i++){
		b[i]+=n%2,n/=2;
	}
}
bool can(int x){
	int b1[46]={};
	for(int j=1;j<=n;j++){
		if(a[j]>>x&1==1)b1[x]++;
	}
	return b1[x]>=m;
}
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)
		ans&=a[i];
	cout<<ans;
	return 0;
}
