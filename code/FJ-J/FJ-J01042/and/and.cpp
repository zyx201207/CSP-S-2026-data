#include<bits/stdc++.h>
using namespace std;
int a[200010],ans;
bool v[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=30;j>=0;j--){
		int s=0;
		for(int i=1;i<=n;i++){
			if(!v[i]&&((a[i]>>j)&1)){
				s++;
			}
		}
		if(s<m)continue;
		for(int i=1;i<=n;i++){
			if(!((a[i]>>j)&1)){
				v[i]=1;
			}
		}
		ans+=(1<<j);
	}
	cout<<ans;
}
