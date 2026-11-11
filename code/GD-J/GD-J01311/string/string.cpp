#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans,b[200005],k;
char s[200005],x[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>s[i];
	a[n+1]=-1,s[n+1]=' ';
	int l=1,cnt=0;
	while(l<=n){
		while(s[l]==s[l+1]&&l<=n)
			cnt+=a[l],l++;
		cnt+=a[l],l++;
		k++,b[k]=cnt,x[k]=s[l-1],cnt=0;
	}
	//cout<<b[1]<<' '<<b[2]<<' '<<b[3];
	int ll=1,rr=k;
	while(ll<rr){
		if(b[ll]==b[rr]&&x[ll]==x[rr])ll++,rr--;
		else if(b[ll]==b[rr])ans+=b[ll],ll++,rr--;
		else if(b[ll]<b[rr]){
				if(x[ll]!=x[rr])ans+=b[ll];
				b[rr]-=b[ll];
				ll++;		
			}
		else {
			if(x[ll]!=x[rr])ans+=b[rr];
			b[ll]-=b[rr];
			rr--;
		}
		//cout<<ans<<'\n';
	}
	cout<<ans;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
3
2 a
2 b
1 c
2
2 a
3 a
*/
