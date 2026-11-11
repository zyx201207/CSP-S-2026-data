#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[210000];
char s[210000];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]); 
		cin>>s[i];
	}
	int l=a[0],r=a[n-1];
	
	int ri=n-1,le=0;
	int ans=0;
	while(ri>le){
		if(l>r){
			if(s[ri]==s[le]){
				ri--;
				l-=r;
				r=a[ri];
			}else{
				ri--;
				l-=r;
				ans+=r;
				r=a[ri];
			}
		}else if(l==r){
			if(s[ri]==s[le]){
				ri--;le++;
				l=a[le];
				r=a[ri];
			}else{
				ri--;le++;
				ans+=l;
				l=a[le];
				r=a[ri];
			}
		}else{
			if(s[ri]==s[le]){
				le++;
				r-=l;
				l=a[le];
			}else{
				le++;
				r-=l;
				ans+=l;
				l=a[le];
			}
		}
	}
	cout<<ans;
	return 0;
} 
