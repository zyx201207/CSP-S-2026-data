//华东师范大学附属贵阳学校 刘睿羽 GZ-J00398   
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
struct node{
	int k;
	char x; 
}a[N];
int n;
int cnt;
signed main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for (int i=1;i<=n;i++){
    	cin>>a[i].k>>a[i].x;
	}
	int l=1,r=n;
	while(l<=r){
		int mi=min(a[l].k,a[r].k);
		if (a[l].x!=a[r].x) {
			cnt+=mi;
		}
		a[l].k-=mi;
		a[r].k-=mi;
		if (a[l].k==0) l++;
		else r--;
	}
	cout<<cnt;
	return 0; 
}

