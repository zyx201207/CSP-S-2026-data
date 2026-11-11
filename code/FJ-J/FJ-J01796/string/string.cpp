#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200100];
char c[200100];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	string s=" ";
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int ans=0,num=0,i=1,vis=n;
	while(1){
		if(c[i]!=c[vis]){
			if(a[i]>=a[vis]){
				ans+=a[vis];
				a[i]-=a[vis];
				vis--;
			}else{
				ans+=a[i];
				a[vis]-=a[i];
				i++;
			}
		}else{
			if(a[i]>=a[vis]){
				a[i]-=a[vis];
				vis--;
			}else{
				a[vis]-=a[i];
				i++;
			}
		}
		if(i>=vis){
			break;
		}
	}
	cout<<ans;
	return 0;
}
