#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,a[200005],cnt=0,maxn=0;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	if(m==1){
		for(int i=0;i<n;i++) maxn=max(maxn,a[i]);
		cout<<maxn;
	}else if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=i;j<n;j++){
				cnt=max(cnt,a[i] & a[j]);
			}
		}
		cout<<cnt;
	}else{
		for(int i=0;i<n;i++) maxn=maxn & a[i];
		cout<<maxn;
	}
	return 0;
}
