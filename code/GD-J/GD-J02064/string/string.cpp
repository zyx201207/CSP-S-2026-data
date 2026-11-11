#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,cnt[N],ans=0;
char x[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt[i];
		cin>>x[i];
	}
	int l=1,r=n;
	while(l<r){
		if(x[l]!=x[r])ans+=min(cnt[l],cnt[r]);
		if(cnt[l]<cnt[r]){
			cnt[r]-=cnt[l];
			l++;
		}else{
			if(cnt[l]==cnt[r]){
				l++;
				r--;
			}else{
				cnt[l]-=cnt[r];
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}/*
2,a
2,b
1,c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
