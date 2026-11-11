#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int const N=1e9+10;
int const midN=1e7+10;
char s[N]; 
char lt[midN],rt[midN];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	int n,cnt=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s[cnt]=c;
			
			++cnt;
		}
	}
	
	cnt--;
	int mid=(1+cnt)/2,l=1,r=1,ans=0;
	if(cnt%2!=0){
		for(int i=mid-1;i>=1;i--){
			lt[l]=s[i];
			++l;
		}
		for(int i=mid+1;i<=cnt;i++){
			rt[r]=s[i];
			++r;
		}
		for(int i=1;i<mid;i++){
			if(rt[i]!=lt[i]) ans++;
		}
	}
	else{
		for(int i=mid;i>=1;i--){
			lt[l]=s[i];
			++l;
		}
		for(int i=mid+1;i<=cnt;i++){
			rt[r]=s[i];
			++r;
		}
		for(int i=1;i<=mid;i++){
			if(rt[i]!=lt[i]) ans++;
		}
	}
	
	cout<<ans;
	return 0;
} 
