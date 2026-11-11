#include<bits/stdc++.h>
using namespace std;
int n,m,a[510000],s[510000],cnt[510000],ans;
int so(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				cnt[i]++;
			}
			ans=max(ans,cnt[i]);
		}
	}
	cout<<ans+1<<endl;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		int mm=m;
		for(int j=i-1;j>=1;j--){
			if(abs(a[i]-a[j])<=mm){
				mm-=abs(a[i]-a[j]);
				a[j]=a[i];			
			}else if(mm<abs(a[i-1]-a[j-1])){
				so();
				return 0;		
			}
		}
	}
	so();
	return 0;
}
