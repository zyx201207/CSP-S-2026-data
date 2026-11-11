#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,cl,cr,ans;
struct node{
	int l;
	char cl;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].l>>a[i].cl;
	for(int i=1,j=n;i<j;i++,j--){
		if(a[i].cl!=a[j].cl) ans+=min(a[i].l,a[j].l);
		cl+=a[i].l,cr+=a[j].l;
		if(cl==cr) continue;
		if(cl>cr){
			if(a[j-1].cl!=a[i].cl)
				ans+=cl-cr;
		}else{
			if(a[i+1].cl!=a[j].cl)
				ans+=cr-cl;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
