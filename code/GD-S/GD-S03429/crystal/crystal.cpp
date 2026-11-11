#include<bits/stdc++.h>//±©Á¦ 
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long nowd=0,cnt=1;
		for(int j=i-1;j>0;j--){
			if(nowd+(a[i]-a[j])>m){
				break;
			}
			else{
				nowd+=a[i]-a[j];
				cnt++;
			}
		}
		if(cnt>ans) ans=cnt;
	}
	cout<<ans;
	return 0;
}
