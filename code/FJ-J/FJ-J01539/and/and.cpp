#include<bits/stdc++.h>
using namespace std;
long long cnt,n,m,a[200005],maxx,b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	maxx=a[1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==a[j]){
				cnt+=1;
			}
		}
		b[i]+=cnt;
	}
	if(cnt==m){
		cout<<maxx;
	}
	return 0;
}
