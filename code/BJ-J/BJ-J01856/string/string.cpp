#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define pb push_back
#define fir first
#define sec second
const int N=2e5+7;
ll n,a[N],sum,r,ans,sumr;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum<800000){
		string s=" ";
		for(int i=1;i<=n;i++){
			while(a[i]--){
				s+=c[i];
			}
		}
		for(int i=1;i<=sum/2;i++){
			if(s[i]!=s[sum-i+1]){
				ans++;
				s[i]=s[sum-i+1];
			}
		}
		cout<<ans;
		return 0;
	}
	sum/=2;
	r=n;
	for(int i=1;i<=n;i++){
//		cout<<sum<<"\n\n";
		if(i>=r){
			break;
		}
		if(sumr){
			if(a[i]-sumr>=0){
	//			cout<<i<<": "<<a[i]<<" "<<sumr<<"\n";
				sum-=sumr;
				if(c[i]==c[r]){
					a[i]-=sumr;
				}else{
					a[i]-=sumr;
					ans+=sumr;
				}
				sumr=0;
				r--;
			}else{
				sum-=a[i];
				if(c[i]==c[r]){
					sumr-=a[i];
				}else{
					sumr-=a[i];
					ans+=a[i];
				}
				continue;
			}
		}
		if(sum-a[i]>=0){
			sum-=a[i];
//			cout<<"sum-a[i]>=0    "<<a[i]<<" "<<a[r]<<"\n";
			while(a[i]>=a[r]){
//				cout<<"while--"<<a[i]<<" "<<a[r]<<"\n";
				if(a[i]==0){
					break;
				}
				if(i==r){
					break;
				}
				if(a[r]==0){
					r--;
					continue;
				}
				if(a[i]==c[r]){
					a[i]-=a[r];
					r--;
					continue;
				}
				ans+=a[r];
				a[i]-=a[r];
				r--;
//				cout<<a[i]<<"\n";
			}
			if(a[i]){
				if(c[i]==c[r]){
					sumr=a[r]-a[i];
					a[r]-=a[i];
				}else{
					ans+=a[i];
					sumr=a[r]-a[i];
					a[r]-=a[i];
				}
//				cout<<ans<<" "<<sumr<<"\n";
			}
		}else{
			if(r==i){
				break;
			}
			if(c[r]==c[i]){
				break;
			}
//			cout<<sum<<" "<<i<<" "<<r<<"\n";
			while(r!=i){
				if(a[i]==c[r]){
					a[i]-=a[r];
					r--;
					continue;
				}
				ans+=a[r];
				a[i]-=a[r];
				r--;
			}
			break;
		}
		if(!sum){
			break;
		}
	}
	cout<<ans;
    return 0;
}
