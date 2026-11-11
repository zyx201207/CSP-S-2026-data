#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,arr[200005],l,r,sum,ans,cnt;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>arr[i]>>c[i];
		sum+=arr[i];
	}
	sum/=2;
	l=1,r=n;
	while(l<r && cnt<sum){
		if(arr[l]<arr[r]){
			if(c[l]!=c[r]) ans+=arr[l];
			arr[r]-=arr[l];
			if(cnt+arr[l]>sum){
				ans-=(cnt+arr[l]-sum);
				break;
			}
			cnt+=arr[l];
			l++;
		}else if(arr[l]>arr[r]){
			if(c[l]!=c[r]) ans+=arr[r];
			arr[l]-=arr[r];
			if(cnt+arr[r]>sum){
				ans-=(cnt+arr[r]-sum);
				break;
			}
			cnt+=arr[r];
			r--;
		}else{
			if(l==r) break;
			else{
				if(c[l]!=c[r]) ans+=arr[l];
				if(cnt+arr[l]>sum){
					ans-=(cnt+arr[l]-sum);
					break;
				}
				cnt+=arr[l]; 
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
