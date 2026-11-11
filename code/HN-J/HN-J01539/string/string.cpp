#include<bits/stdc++.h>
using namespace std;
#define int long long
struct str{
	int m;
	char c;
};
str a[100010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,tmp,ans=0,s=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;
		s+=a[i].m;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].c==a[r].c){
			if(a[l].m>a[r].m){
				a[l].m-=a[r].m;
				r--;
			}
			else{
				a[r].m-=a[l].m;
				l++;
			}
		}
		else{
			if(a[l].m>a[r].m){
				a[l].m-=a[r].m;
				ans+=a[r].m;
				r--;
			}
			else{
				a[r].m-=a[l].m;
				ans+=a[l].m;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
