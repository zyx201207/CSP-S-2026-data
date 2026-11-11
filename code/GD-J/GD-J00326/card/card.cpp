#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
bool fl;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==a[i-1]){
			fl=1;
			break;
		}
	}
	if(fl){
		for(int x=1;x<=m;x++){
			for(int i=n;i>=1;i--){
				if(a[i]==x){
					cout<<i<<" ";
					break;
				}
			}
		}
	}else{
		for(int x=1;x<=m;x++){
			for(int i=1;i<=n;i++){
				if(a[i]==x){
					cout<<i<<" ";
					break;
				}
			}
		}
	}
	return 0;
}
