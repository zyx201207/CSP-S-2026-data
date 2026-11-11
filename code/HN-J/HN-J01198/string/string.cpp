#include<bits/stdc++.h>

using namespace std;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans = 0;
	int n;
	cin>>n;
	long long a[n];
	string s = "";
	for(int i = 1;i<=n;i++){
		string m;
		cin>>a[i]>>m;
		s+=m;
	}
	int l = 1,r = n;
	while(l<r){
		if(s[l]!=s[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				a[r] = 0;
				r--;
			}else{
				if(a[l]<a[r]){
					ans+=a[l];
				    a[r]-=a[l];
				    a[l] = 0;
				    l++;
				}else{
					ans+=a[l];
					a[l] = 0;
					a[r] = 0;
					l++;
					r--;
				}
			}
		}else{
			if(a[l]>a[r]){
				a[l]-=a[r];
				a[r] = 0;
				r--;
			}else{
				if(a[l]<a[r]){
					a[r]-=a[l];
					a[l] = 0;
					l++;
				}else{
					l++;
					r--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
