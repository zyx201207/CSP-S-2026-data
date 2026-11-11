#include<bits/stdc++.h>
using namespace std;
long long  n,m,k=1,a[500005],minn=-1005;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	long long z=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=n;m>=i;j--){
			if(j<=0||a[j-1]<a[j]-z){
				break;
			}
			if(a[j]==a[j-1]){
				k++;
			}else{
				a[j-1]+=min(m,a[j+1]-a[j]);
				m-=min(m,a[j-1]-a[j]);
				if(a[j]==a[j-1]){
					k++;
				}
			}
			minn=max(minn,k);
		}
	}
	cout<<minn;
	return 0;
}
