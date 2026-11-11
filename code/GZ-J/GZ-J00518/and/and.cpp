//GZ-J00518 ЌхичЇ≠ 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[int(2e5+5)],ans,zzz;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=700000;i++){
		bitset<20> x=i;
		int cnt=0;
		zzz=0;
		for(int j=0;j<20;j++){
			if(zzz==0 and x[j]==1)zzz=a[j];
			cnt+=x[i];
			if(cnt==m){
				for(int y=1;y<=m;y++){
					if(x[y])zzz&=a[y];
				}
			}
			ans=max(ans,zzz);
		}

		cout<<ans;
	}

	return 0;
}
