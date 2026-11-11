#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int n,m;
int a[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int o=1;o<=n;o++){
		vector<int> now;
		int l=o;
		while(l<=n){
			for(int r=n;r>=l;r--){
				if(a[l]==a[r]){
					now.emplace_back(a[l]);
					l=r+1;
					break;
				}
			}
		}
		for(int it:now){
			ans[it]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
