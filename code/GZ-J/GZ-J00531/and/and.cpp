//GZ-J00531 КывужабЇ ЩЬ№Љаљ 
#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[30000],i,b[3000],j,maxd,ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>a[i];
	}maxd=a[0]&a[1];
for(i=2;i<m;i++){
	maxd=maxd&a[i];
	}

for(i=m;i<n;i++){
		ans=a[i]&a[i+1];
	for(j=i;j<i+m;j++){
	ans=ans&a[i];
	}
	maxd=max(maxd,ans);
	}	
		cout<<maxd;
	return 0;
}
