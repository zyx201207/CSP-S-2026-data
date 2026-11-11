#include<bits/stdc++.h>
using namespace std;
long long n,m[2000005],a[2000005],ans,l=1,r=m[1];
char c[2000005],b[4000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m[1]=a[i]+m[1];
	}
	int s=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			b[s]=c[i];
			s++;
		}
	}
	for(int i=1;i<=n;i++){
		if(l==r){
			break;
		}else{
			if(b[l]!=b[r]){
				ans++;
				l++;r--;
			}else{
				l++;r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
