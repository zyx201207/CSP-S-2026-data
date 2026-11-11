#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
struct node{
	int k;
	char c;
};
int n,ans,len,l1,r1,l2,r2;
node a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].k>>a[i].c;
	}
	l1=1,r1=a[n].k;
	l2=1,r2=n;
	while(l2<r2){
		if(a[l2].k-l1+1>r1){
			if(a[l2].c!=a[r2].c){
				ans+=r1;
			}
			l1+=r1;
			r2--;
			r1=a[r2].k;
		}
		else if(a[l2].k-l1+1<r1){
			if(a[l2].c!=a[r2].c){
				ans+=a[l2].k-l1+1;
			}
			r1-=a[l2].k-l1+1;
			l2++;
			l1=1;
		}
		else{
			if(a[l2].c!=a[r2].c){
				ans+=a[l2].k-l1+1;
			}
			r2--;
			r1=a[r2].k;
			l2++;
			l1=1;
		}
	}
	cout<<ans;
	return 0;
}

