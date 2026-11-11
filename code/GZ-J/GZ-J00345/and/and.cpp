//GZ-J00345 遵义市第四中学 李禹宸 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int mx;
int l,r;
map<int,int> mp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(mx<=(a[i]&a[j])){
				mx=max(mx,(a[i]&a[j]));
				l=i,r=j;
			}
		}
	}
	m-=2;
	int o=mx;
	mp[r]=1;
	mp[l]=1;
	mx=0;
	while(m--){
		for(int i=1;i<=n;i++){
			if(mp[i]==1){
				continue;
			}
			if(mx<=(o&a[i])){
				l=i;
				mx=max(mx,(o&a[i]));
			}
		}
		o=mx;
		mp[l]=1;
	}
	cout<<o;
	return 0;
}
