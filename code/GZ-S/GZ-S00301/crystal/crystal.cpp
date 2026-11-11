//GZ-S00301贵阳市南明区华麟学校杨景添 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010];
int ans=INT_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=a[n];i++){
		int cnt=m,ans1=0;
		for(int j=1;j<=i;j++){
			if(a[j]<i){
				if(i-a[j]<=cnt){
					cnt-=i-a[j];
					ans1++;
				}
			}else if(a[j]=i){
				ans1++;
			}
		}
		if(ans1>ans){
			ans=ans1;
		}
	}
	cout<<ans;	
	return 0;
}
