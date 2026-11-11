#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,a[200005],f;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=29;i>=0;i--){
		int res=0;
		f+=(1<<i);
		for(int j=1;j<=n;j++){
			if((a[j]&f)==f)res++;
		}
		if(res<k)f-=(1<<i);
	}
	cout<<f;
	return 0;
}
