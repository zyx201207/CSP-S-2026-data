#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],sum[500010],top[500010];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum[i]++;
		break;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			top[i]+=a[i]-a[j]+1; 
		}
	}
    cout<<m;
	return 0;
}
