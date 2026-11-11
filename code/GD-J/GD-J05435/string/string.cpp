#include <bits/stdc++.h>
using namespace std;
long long n,ans=0;
struct ct{
	long long len;
	char sub;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].len >> a[i].sub;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].len>a[r].len){
			if(a[l].sub==a[r].sub){
				a[l].len-=a[r].len;
				r--;
				continue;
				
			}
			else{
				ans+=a[r].len;
				a[l].len-=a[r].len;
				r--;
				continue;
			}
		}
		else if(a[l].len<a[r].len){
			if(a[l].sub==a[r].sub){
				a[r].len-=a[l].len;
				l++;
				continue;
				
			}
			else{
				ans+=a[l].len;
				a[r].len-=a[l].len;
				l++;
				continue;
			}
		}
		else if(a[l].len==a[r].len){
			if(a[l].sub==a[r].sub){
				l++;
				r--;
				continue;
				
			}
			else{
				ans+=a[l].len;
				l++;
				r--;
				continue;
			}
		}
	}
	cout << ans;
}
