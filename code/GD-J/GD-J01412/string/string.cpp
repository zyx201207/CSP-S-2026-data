#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
int n,a[200005];
long long ans;
char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i]>>ch[i];
	int l=1,r=n;
	while(l<r){
		if(ch[l]==ch[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]>a[r]){
				ans+=1ll*a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				ans+=1ll*a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
