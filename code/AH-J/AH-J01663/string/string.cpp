#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],ans=0;
char b[N];
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	int i=1,j=n;
	while(i<j&&i<=n&&j>=1){
		if(a[i]>a[j]){
			if(b[i]==b[j]){
				a[i]-=a[j];
				j--;
			}else{
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
		}else{
			if(b[i]==b[j]){
				a[j]-=a[i];
				i++;
			}else{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
		}
		while(a[i]==0&&i<=n)i++;
		while(a[j]==0&&j>=1)j--;
	}
	cout<<ans;
	return 0;
}
