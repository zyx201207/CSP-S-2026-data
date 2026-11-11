#include<bits/stdc++.h>
using namespace std;
long long a[200005];long long n,m,cnt=1,ans=0,cha;
bool isp(){
	
	int ch=a[2]-a[1];cha=ch;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=ch)return false;
	}
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(isp()){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=i*(a[2]-a[1]);
		//	cout<<ans;
			if(ans>m){
				cout<<cnt;return 0;
			}
			cnt++;
		}
	} 
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++){
		cnt=1;
		int mi=m;
		int p=a[i];
		for(int j=i;j>=1;j--){
			int zhi=p-a[j];
			if(mi-zhi>0){
				cnt++;
				mi-=zhi;
			}else break;
		}
		ans=max(ans,cnt); 
	}cout<<ans;
	return 0;
} 
