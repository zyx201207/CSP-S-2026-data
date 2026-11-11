#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,le,ri,sum;
char s[200009];
int a[200009];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	le=1,ri=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	while(le<ri){
		int h=min(a[le],a[ri]);
		if(s[le]==s[ri]){
			a[le]-=h;
			a[ri]-=h;
		}else{
			sum+=h;
			a[le]-=h;
			a[ri]-=h;
		}
		if(a[le]==0) le++;
		if(a[ri]==0) ri--;
	}
	cout<<sum;
	return 0;
}
