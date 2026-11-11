//GZ-J00705 遵义市第十六中学 赵思杰 
#include<bits/stdc++.h>
using namespace std;
const long long N=200005;
int main(){
	freopen("string.in",r,stdin);
	freopen("string.out",w,stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,s;
	string c,st[N];
	long long a[N],len=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s>>c;
		len+=s;
		for(int j=len-s+1;j<=len;j++){
			st[j]=c;
		}
	}for(long long l=1,r=len;l<=len/2,r>=len/2;l++,r--){
		if(st[l]!=st[r]){
			st[r]=st[l];
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
