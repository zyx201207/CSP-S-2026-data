#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	int a[100005];
	int maxk=0,n,m,sumk=INT_MAX,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxk=max(maxk,a[i]);
		sumk&=a[i];
	}
	if(n<=20){
		int maxn=0;
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n;i++){
				if(j&(i<<(i-1))){
					cnt++;
					sumk&=a[i];
				}
			}
			if(cnt!=m){
				continue;
			}
			maxn=max(maxn,sum);
		}
		cout<<maxn;
	}
	return 0;
}
