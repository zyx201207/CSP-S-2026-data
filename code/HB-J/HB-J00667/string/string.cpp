#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,bk[200010],l=0,r=0,tnt=0;
string s[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>bk[i]>>s[i];
	}
	l=1;r=n;
	while(l<r){
		if(bk[l]>bk[r]){
			if(s[l]!=s[r]) tnt+=bk[r];
			bk[l]-=bk[r];
			bk[r]=0;
			r--;
		}
		else{
			if(s[l]!=s[r]) tnt+=bk[l];
			bk[r]-=bk[l];
			bk[l]=0;
			l++;
			if(bk[r]==0) r--;
		}
	}
	cout<<tnt;
	return 0;
}




