#include<bits/stdc++.h>
using namespace std;
int n,a[200020];
long long ans;
char b[200020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	long long l=1,l1=0,r=n,r1=0;
	while(l<r){
		if(b[l]==b[r]){
			if(a[l]-l1==a[r]-r1){
				r--;
				l++;
				r1=0;
				l1=0;
			}else if(a[r]-r1>a[l]-l1){
				r1+=(a[l]-l1);
				l++;
				l1=0;
			}else{
				l1+=(a[r]-r1);
				r--;
				r1=0;
			}
		}else{
			if(a[l]-l1==a[r]-r1){
				ans+=(a[l]-l1);
				r--;
				l++;
				r1=0;
				l1=0;
			}else if(a[r]-r1>a[l]-l1){
				ans+=(a[l]-l1);
				r1+=(a[l]-l1);
				l++;
				l1=0;
			}else{
				ans+=(a[r]-r1);
				l1+=(a[r]-r1);
				r--;
				r1=0;
			}
		}
	}
	cout<<ans;
	return 0;
}

