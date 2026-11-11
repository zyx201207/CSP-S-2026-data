#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
char a[N];
int s[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>s[i]>>a[i];
    int l=1,r=n;
    while(l<r){
		if(a[l]!=a[r]) sum+=min(s[l],s[r]);
		if(s[l]>s[r]) s[l]-=s[r],r--;
		else if(s[l]==s[r]) l++,r--;
		else if(s[l]<s[r]) s[r]-=s[l],l++;
	//	cout<<l<<' '<<r<<'\n'; 
	}
	cout<<sum;
   return 0;
}
//guan zhu luogu cp_zry
//hui wen xing zhi
