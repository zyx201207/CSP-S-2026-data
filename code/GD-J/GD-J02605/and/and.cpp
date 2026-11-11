#include<bits/stdc++.h> 
using namespace std;
int n,m;
long long ans;
long long a[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m == 1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
	}else if(m == 2){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					ans = max(ans,a[i]&a[j]);
				}
			} 
		}
		cout<<ans;
	}
}
