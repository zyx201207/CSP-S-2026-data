#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50001],qz[50001],ans[50001];

bool cmp2(int a1,int a2){
	return a1>a2;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++){
		int k=a[i],ma_x=0;
		for(int j=i;j<=n;j++){
			ma_x+=k-a[j];
			if(ma_x<=m){
				ans[i]++;
			}
			else
				continue;
		}
	}
	sort(ans+1,ans+n+1,cmp2);
	cout<<ans[1];
	
	return 0;
}
