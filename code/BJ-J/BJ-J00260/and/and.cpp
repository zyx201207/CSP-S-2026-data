#include <bits/stdc++.h>
using namespace std;
int a[200050];
bool p[200050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ans=0;
	for(int xs=1;xs<=n;xs++){
		cin>>a[xs];
	}
	for(int k=30;k>=0;k--){
		int num=0;
		for(int xs=1;xs<=n;xs++){
			if(!p[xs]&&a[xs]&(1<<k)){
				num++;
			}
		}
		if(num>=m){
			ans+=1<<k;
			for(int xs=1;xs<=n;xs++){
				if(!p[xs]&&!(a[xs]&(1<<k))){
					p[xs]=1;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
