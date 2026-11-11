#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,maxx=-1;
int main(){
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<(1<<n);i++){
		int num=0;
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				ans=a[j];
				break;
			}
		}
		for(int j=1;j<=n;j++){
			if(i&(1<<(j-1))){
				num++;
				ans=ans and a[j];
			}
		}
		if(num==m){
			maxx=max(maxx,ans);
		}
	}
	cout<<maxx;
	return 0;
}
