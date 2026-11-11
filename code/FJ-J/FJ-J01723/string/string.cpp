#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,a[N],sum,ans;
bool flag=0;
char c[N];
map<char,int> mp;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	sum/=2;
	int cnt=0,j=n;
	for(int i=1;i<=n;i++){
		cnt+=a[i];
		if(flag) break;
		if(cnt>=sum){
			a[i]=a[i]-(cnt-sum);
			flag=1;
		}
		while(a[i]){
			if(a[j]==0) j--;
			if(a[j]>=a[i]){
				if(c[j]!=c[i]){
					ans=ans+a[i];
				}
				a[j]-=a[i];
				a[i]=0;
			}else{
				if(c[j]!=c[i]){
					ans=ans+a[j];
				}
				a[i]-=a[j];
				a[j]=0;
			}
		}
	}
	cout<<ans;
	return 0;
} 
