#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],w=30,cnt,ans,l=1,r;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	r=n;
	for(int z=1;z<=n;z++){
		cin>>a[z];
	}
	sort(a+1,a+1+n,cmp);
	while(w>=0){
		cnt=0;
		for(int z=l;z<=r;z++){
			if(a[z]&(1<<w))cnt++;
			else break;
		}
		if(cnt>=m){
			for(int z=l;z<=r;z++){
				if(a[z]&(1<<w)){
					l=z;
					break;
				}
			}
			for(int z=r;z>=l;z--){
				if(a[z]&(1<<w)){
					r=z;
					break;
				}
			}
			ans|=(1<<w);
		}
		w--;
	}
	cout<<ans;
	return 0;
}
