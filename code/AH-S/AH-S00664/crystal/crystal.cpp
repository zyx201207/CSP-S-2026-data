#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],s[500001],i,j,x,maxx,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=a[i]-a[i-1];
	}
	i=n;
	j=n;
	maxx=-1;
	while(true){
		ans=0;
		for(int k=i;k<=j;k++){
            x+=s[i];
            ans++;
		}
		if(ans<m){
			maxx=max(maxx,x);
			i--;
		}else if(ans>m){
			j--;
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}

