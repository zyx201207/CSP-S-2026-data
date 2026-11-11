#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	bool b=1;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		if(c[i]!=c[i-1]&&i!=1)b=0;
		
	}
	if(b==1){
		cout << 0;
		return 0;
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(c[l]==c[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				l++;
				r--;
			}
		}else{
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[l]==a[r]){
				ans+=a[l];
				l++;
				r--;
			}
		}
	}
	cout << ans << endl;
	return 0;
} 
