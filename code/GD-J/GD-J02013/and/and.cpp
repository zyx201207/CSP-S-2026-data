#include<bits/stdc++.h>
using namespace std;
int n,m,a[20010];
bool cmp(int x,int y){
	int idx=1,idy=1,a[31],b[31];
	while(x){
		a[idx++]=x%2;
		x/=2;
	}
	while(y){
		b[idy++]=y%2;
		y/=2;
	}
	if(idx==idy){
		for(int i=idx-1;i>=1;i--){
			if(a[i]!=b[i]){
				return a[i];
			}
		}
	}else{
		return idx>idy;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	int ans=pow(2,30)-1;
	for(int i=1;i<=m;i++) ans=(ans&a[i]);
	cout<<ans;
	return 0;
}
