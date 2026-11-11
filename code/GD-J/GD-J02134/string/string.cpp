#include<bits/stdc++.h>
using namespace std;
const int nm=2e5+5;
int n,a[nm];
long long cnt;
char c[nm];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int l=0,r=n+1;
	long long cl=0,cr=0;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	while(l<r){
		if(cl<cr){
			l++;
			if(c[l]!=c[r])cnt+=min(1ll*a[l],cr-cl);
			cl+=a[l];
		}
		else{
			r--;
			if(c[l]!=c[r])cnt+=min(1ll*a[r],cl-cr);
			cr+=a[r];
		}
	}
	cout<<cnt;
	return 0;
}
//输入不了换行符，会有歧义 
