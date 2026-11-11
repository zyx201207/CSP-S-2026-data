#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
struct node{
	int num;
	char c;
}a[200005]; 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	} 
	int ans,l,lstl,r,lstr;
	ans = 0;
	l = 1;
	lstl = a[1].num;
	r = n;
	lstr = a[n].num;
	while(l<r){
		if(lstl<lstr){
			ans = ans+lstl*(a[l].c!=a[r].c);
			lstr = lstr-lstl;
			lstl = 0;
		}else{
			ans = ans+lstr*(a[l].c!=a[r].c);
			lstl = lstl-lstr;
			lstr = 0;
		} 
		if(!lstl){
			lstl = a[++l].num;
		}
		if(!lstr){
			lstr = a[--r].num;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

