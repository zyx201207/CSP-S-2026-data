#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m,c;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	c=m;
	sort(a+1,a+n+1);
	int l=1,r=1,h=a[1],ma=1;
	while(r<=n&&l<=n){
		if(a[r+1]==h) r++;
		else if(m>=(a[r+1]-h)*(r-l+1)){
			m-=(a[r+1]-h)*(r-l+1);
			r+=1;
			h=a[r];
		}
		else{
		if(c<=(a[r+1]-h)*(r-l+1)){
			l=r+1;
			m=c;
			r+=1;
			h=a[r];
		}
		else {	m+=(h-a[l]);
			l+=1;
		}
		}
		ma=max(ma,r-l+1);
		
	}
	cout<<ma;
	return 0;
}
