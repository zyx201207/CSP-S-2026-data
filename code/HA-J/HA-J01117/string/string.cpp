#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[200005];
char c[200005];
long long sum;
long long num;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	int m=0;
	int l=0,r=n;
	int pan=0;
	for (int i=1;i<=n;i++){
		l++;
		m=a[l];
		num+=m;
		if (num>=sum/2){
			m=m-(num-(sum/2));
			pan=1;
		}
		while(m>0){
			if (a[r]<=m){
				if (c[l]!=c[r]){
					ans+=a[r];
				}
				m-=a[r];
				r--;
			}
			else{
				if (c[l]!=c[r]){
					ans+=m;
				}
				m=0;
				a[r]-=m;
			}
		}
		if (pan==1){
			break;
		}
	}
	cout<<ans;
	return 0;
}
