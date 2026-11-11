#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
int a[N];
int l,r;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	int ans=0;
	while(l<=r){
		if(c[l]==c[r]){
			if(a[l]<a[r]){
				a[r]-=a[l];
				l++;
			}else{
				a[l]-=a[r];
				r--;
			}
		}else{
			if(a[l]<a[r]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				ans+=a[r];
				a[l]-=a[r];
				r--; 
			}
		}
	}
	cout<<ans; 
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
/*aaaaaaaaaaaaaaa
bbccddeeaaccbbe*/
