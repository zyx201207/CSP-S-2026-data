//GZ-J00627 ·¶¿£ãñ 
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	int n;
	cin>>n;
	int num[n+1];
	char str[n+1];
	for(int i=1;i<=n;i++){
		cin>>num[i]>>str[i];
	}
	int l=1,r=n;
	int ans=0;
	while(l<r){
		if(num[l]!=num[r]){
			if(num[l] > num[r]){
				if(str[l]!=str[r]){
					ans+=(num[r]);
				}
				num[l]-=num[r];
				r--;
			}
			else{
				if(str[l]!=str[r]){
					ans+=(num[l]);
				}
				num[r]-=num[l];
				l++;
			}
			
		}
		else{
			if(str[l]!=str[r]){
				ans+=(num[l]);
			}
			l++;
			r--;
		} 
	}
	cout<<ans;
	return 0;
}
