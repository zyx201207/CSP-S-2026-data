#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cn,ma=1,v,j ;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=n;i>1;i--){
		cn=0;
		j=i-1;
		v=1;
		while(cn+a[i]-a[j]<=m&&j>=1){
			cn+=a[j];
			j--;
			v++;
		}
		if(v>ma)ma=v;
		if(v>=i-1)break;
	}
	cout<<ma;
	return 0; 
}
