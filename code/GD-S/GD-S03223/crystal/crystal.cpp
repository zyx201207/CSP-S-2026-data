#include<bits/stdc++.h>
using namespace std;
long long n,m,p=0,ma=0,y=0;
long long a[550000],k[550000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		p=0;
		y=0;
		for(int j=0;j<n;j++) k[j]==0;
		for(int j=0;j<n;j++)
			k[j]=a[i]-a[j];
		sort(k,k+n);
		for(int j=0;j<n;j++){
			if(k[j]>=0 and p+k[j]<=m){
				p+=k[j];
				y+=1;
			}
		}
		ma=max(ma,y);
	}
	if(ma==1) cout<<0;
	else cout<<ma;
	return 0;
}
