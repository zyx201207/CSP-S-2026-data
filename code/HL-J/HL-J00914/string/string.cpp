#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000010],b,ans;
string s[200100];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		b+=a[i];
	}
//	ans=(b+1)/2;
	for(int i=1,j=n;i<j;){
		if(s[i]==s[j]){
			if(a[i]>a[j]){
//				ans-=a[j];
				a[i]-=a[j];
				j--;
			}
			else{
//				ans-=a[i];
				a[j]-=a[i];
				i++;
			}
		}
		else{
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
			else{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}