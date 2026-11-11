#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,s=0;
	cin>>n>>m;
	int a[100005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	int q,t,d;
		if(n%2==0)  {
	q=a[n/2]; t=n/2; d=n/2;
}
	else {
	 q=a[n/2+1]; t=n/2+1; d=n/2+1;
}
int cc=0,k=0,zz=0;
for(int i=t-1;i>=1;i--){
	cc+=q-a[i];
}
for(int i=t+1;i<=n;i++){
	k+=a[i]-q;
}
if(cc<k&&cc<m){
	m-=cc;
	zz+=t;
	while(m>0){
		for(int i=t+1;i<=n;i++){
			if(a[i]-q<=m){
				m-=a[i]-q;
				zz++;
				break;
			}
		}	
	}
}
if(cc>k&&k<m){
	m-=k;
	zz+=n-t+1;
	while(m>0){
		for(int i=t-1;i>=1;i--){
			if(q-a[i]<=m){
				m-=q-a[i];
				zz++;
				break;
			}
		}	
	}
}
	while(m>0){
				if(q-a[t-1]<a[d+1]-q) {
					m-=q-a[t-1];                         
					if(a[t-1]==q) {
					zz++;
					t--;
					continue;
				}
				}
					if(q-a[t-1]>a[d+1]-q) {
					 m-=a[d+1]-q;
					if(a[d+1]==q) {
					zz++;
					d++;
					continue;
				}
				}
				}
cout<<zz;
	return 0;
}
