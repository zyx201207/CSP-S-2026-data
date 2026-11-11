#include<bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(nullptr);
	freopen("string1.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans = 0;
	int n;
	cin>>n;
	int a[n];
	string c;
	string c1;
	for(int i = 0;i<n;i++){
		cin>>a[i];
		cin>>c1;
		c+=c1;
	}
	for(int i = 0;i<n;i++){
		if(a[i]<a[n-1]){
			if(c[i]==c[n-1]) {
				continue;
			}else{
				ans+=a[i];
			}
		}else{
			if(c[i]==c[n-1]) {
				continue;
			}else{
			ans+=a[n-1];
			}
		}
	}
	cout<<ans;
	return 0;
}
