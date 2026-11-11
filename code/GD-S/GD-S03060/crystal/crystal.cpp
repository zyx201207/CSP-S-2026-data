#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		long long sum=0,cnt=0;
		for(int j=i-1;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum<=m){
				cnt++;
			}
			else{
				break;
			}
		}
		if(cnt>0){
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
