//GZ-J00437 张瑞晨 清华中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],maxs=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxs=max(maxs,a[i]);
		}
	}else if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i;j<=n;j++){
				maxs=max(maxs,(a[i]&a[j]));
			}
		}
	}
	cout<<maxs;
	return 0;
	return 0;
}
