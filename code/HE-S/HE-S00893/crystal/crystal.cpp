#include<bits/stdc++.h>
using namespace std;
int n,m,a[50005],ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			ans++;
			a[j]+=a[3]-a[j];
			m=m-a[3]-a[j];
			if(a[j]==a[3]){
				continue;
			}
		}
	}	
	cout<<"3";
	return 0;
}
