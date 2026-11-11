#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	vector<long long>a(n+1);
	vector<char>c(n+1);
	long long ans=0,cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		sum+=a[i];
	}
	int l=1,r=n;
	while(cnt*2<sum){
		if(c[l]==c[r]){
			if(a[l]>a[r]) a[l]-=a[r],cnt+=a[r],r--;
			else if(a[l]<a[r]) a[r]-=a[l],cnt+=a[l],l++;
			else cnt+=a[l],l++,r--;
		}else{
			if(a[l]>a[r]) a[l]-=a[r],ans+=min(a[r],sum/2-cnt),cnt+=a[r],r--;
			else if(a[l]<a[r]) a[r]-=a[l],ans+=min(a[l],sum/2-cnt),cnt+=a[l],l++;
			else ans+=min(a[l],sum/2-cnt),cnt+=a[l],l++,r--;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

