#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m,a[N],sum,ans=-1;
int mx=-1,id;
int fs;
bool flag;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max((ll)mx,abs(a[i]));
	sort(a+1,a+n+1);
	if(mx<=100){
		for(int i=-100;i<=100;i++){
			sum=0,fs=-1,flag=0;
			for(int j=n;j>=1;j--){
				if(a[j]>i) continue;
				if(fs==-1) fs=j;
				sum+=i-a[j];
				if(sum>m){
					ans=max(ans,(ll)(fs-j));
					flag=1;
					break;
				}
			}
			if(!flag){
				ans=max(ans,(ll)fs);
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	for(ll i=1;i<=n;i++){
		sum=0,flag=0;
		for(int j=i;j>=1;j--){
			sum+=a[i]-a[j];
			if(sum>m){
				ans=max(ans,i-j);
				flag=1;
				break;
			} 
		}
		if(!flag) ans=max(ans,i);
	}
	cout<<ans<<'\n';
	return 0;
} 
