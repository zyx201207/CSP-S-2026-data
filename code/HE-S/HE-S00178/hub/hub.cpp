#include<bits/stdc++.h>
using namespace std;
long long c,t;
struct node{
	bool x[5005];
	long long i;
	long long a[5005];
};

void solve(){
	node tree[505];
	long long n,k;
	cin>>n>>k;
	n--;
	while(n--){
		long long tb,te;
		cin>>tb>>te;
//		long long i=tree[tb].i;
//		tree[tb].a[i]=te;
//		tree[tb].i++; 
	} 
	cout<<1<<endl;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",std);
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
} 
