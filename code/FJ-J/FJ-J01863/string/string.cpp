#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll mid,md,s[200010],l,r,k,ans,mx;
struct nd{
	ll a;
	char c;
}x[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].c;
		mx=max(mx,x[i].a);
	}
	if(n<=10&&mx<=50){
		string d=" ";
		for(int i=1;i<=n;i++){
			l+=x[i].a;
			for(int j=1;j<=x[i].a;j++){
				d+=x[i].c;
			}
		}
		mid=(l+1)/2+1;
		for(int i=mid;i<=l;i++){
			if(d[i]!=d[l-i+1])ans++;
		}
		cout <<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+x[i].a;
	}
	md=(s[n]+1)/2+1;
	mid=upper_bound(s+1,s+n+1,md)-s;
	k=mid-1;
	for(int i=mid;i<=n;i++){
		if(x[i].c!=x[k].c){
			ans+=x[i].a;
			k--;
		}
	}
	cout <<ans;
	return 0;
}/*

3
2 a
2 b
1 c



2
2 a
3 a





6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
