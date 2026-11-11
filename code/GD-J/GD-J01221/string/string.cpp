#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
int ans;
struct o{
	int cnt;
	char c;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].c;
	}int i=1,j=n;
	while(i<j){
		if(a[i].cnt<a[j].cnt){
			if(a[i].c!=a[j].c) ans+=a[i].cnt;
			a[j].cnt-=a[i].cnt;
			i++;
		}else{
			if(a[i].c!=a[j].c) ans+=a[j].cnt;
			a[i].cnt-=a[j].cnt;
			j--;
		}
	}cout<<ans;
	return 0;
}
