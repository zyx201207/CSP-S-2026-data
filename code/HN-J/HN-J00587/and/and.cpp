#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int max1=a[0];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]&&a[i]>0){
				if(a[i]>max1){
					max1=a[i];
				}
			}
		}
	}
	cout<<max1;
	return 0;
}
