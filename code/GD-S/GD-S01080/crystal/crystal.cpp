#include<bits/stdc++.h>
using namespace std;
long long s[500005],s1[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n=0,m=0,lon=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		lon++;
	}
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		s1[i]=s1[i-1]+(abs(s[i-1])-abs(s[i]))*(i-1);
	} 
	int l=1,r=1;
	r=(l+r)/2;
	int maxx=-1;
	while(l<=n&&r<=n){
		if(m+(s1[r]-s1[l]-(l-1)*(s[l]-s[r]))<0){
			l++;
		}
		else if(m+(s1[r]-s1[l]-(l-1)*(s[l]-s[r]))>0){
			maxx=max(maxx,r-l+1);
			r++;
			
		}
		else{
			maxx=max(maxx,r-l+1);
			r++;
			
			
		}
	}
	cout<<maxx;
	return 0;
} 
