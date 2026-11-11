#include<bits/stdc++.h>
int const N=1e6+10;
long long a[N],s[N],n,ma,m,maxx;
using namespace std;
long long cry(long long t){
	ma=m;
	maxx=1;
	for(int j=1;j<n;j++)s[j-1]=t-a[j];
	sort(s,s+n);
	for(int j=1;j<m;j++){
		if(ma>=0){
			if(s[j]>0){
				s[j]--;
				ma--;
				}}
			else break;}
	for(int k=0;k<n;k++)if(s[k]==0)maxx++;
	return maxx;}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long maxcry=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){maxcry=max(maxcry,cry(a[i]));}
	cout<<maxcry;
	return 0;
	}
