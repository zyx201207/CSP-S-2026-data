#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,mx=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			continue;
		}
		long long inx=i-1,ls=m,jishu=1;
		while(ls>=0){
			ls=ls-(a[i]-a[inx]);
			if(ls<0){
				break;
			}
			jishu++;
			inx--;
			if(inx<1){
				break;
			}
			
		}
		mx=max(mx,jishu);
	}
	cout<<mx;
	return 0;
}
