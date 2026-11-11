#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=5e5+5;
LL a[N],b[N],n,m,Max=1;
bool check(LL i,LL j){
	LL cnt=a[i]*(i-j+1)-(b[i]-b[j-1]);
	return cnt<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1,sz=(int)n;i<=sz;i++)
	    b[i]=b[i-1]+a[i];
	for(LL i=1;i<=n;i++){
		LL L=1,R=i;
		while(L<R){
		    LL mid=(L+R)/2;
			if(check(i,mid)==1) R=mid;
			else L=mid+1;
		}
		Max=max(Max,(i-L+1));
	}
	cout<<Max<<'\n';
	return 0;
}
