#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt=0,s=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int j=1,k=1;
	for(int i=2;i<=n;i++){
		if(j>=1){
			while(k<i){
				s=s+a[k];
				k++;
			}
			cnt=a[i]*j-s;
		}
		j++;
		if(cnt==m){
			cout<<i;
		}
	}
	return 0;
}
