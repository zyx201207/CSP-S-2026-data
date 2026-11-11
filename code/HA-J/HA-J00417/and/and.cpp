#include<bits/stdc++.h>
using namespace std;
int a[200010],aa[200010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,lk=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		aa[i]=a[i];
		if(a[i]==1)lk=1;
	}
	sort(a+1,a+1+n,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	if(ans!=0)cout<<ans<<endl;
	else {
		if(m==2){
			int ans=0;
			for(int i=1;i<n;i++){
				for(int j=i;j<=n;j++){
					ans=max(ans,aa[i]&aa[j]);
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
