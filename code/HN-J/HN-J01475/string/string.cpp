#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,a[N];
char c[N];
int L;
int l[N],r[N];
int ans1,ans2;
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
		l[i]=r[i-1]+1;
		r[i]=l[i]+a[i]-1;
	} 
	int k=L+1>>1;
	int sk;
	for(int i=1;i<=n;i++) if(l[i]<=k&&k<=r[i]) sk=i;
	for(int i=1,j=n,si=1,sj=L;(L%2==1?si<k&&k<sj:si<=k&&k<sj);){
		int l1=(i==sk?k:r[i])-si+1,l2=sj-(j==sk?k:l[j])+1;
		if(l1<=l2){
			sj-=l1;
			si+=l1;
			ans1+=(c[i]!=c[j])*l1;
			if(!(l[j]<=sj&&sj<=r[j])) j--;
			if(!(l[i]<=si&&si<=r[i])) i++;
		} 
		else {
			sj-=l2;
			si+=l2;
			ans1+=(c[i]!=c[j])*l2;
			if(!(l[j]<=sj&&sj<=r[j])) j--;
			if(!(l[i]<=si&&si<=r[i])) i++;
		}
	}
	cout<<ans1;
	return ;
} 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int oT_To=1;
//   cin>>oT_To;
	while(oT_To--) solve();
	return 0;
}
