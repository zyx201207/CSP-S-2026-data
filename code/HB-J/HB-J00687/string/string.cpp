#include <bits/stdc++.h>
using namespace std;
struct xc{
	long long cnt=0;
	char s;
}a[200005];
int n;
long long x(){
	long long ans=0;
	for(int p=1,q=n;p<q;){
		if(a[p].s!=a[q].s){
			ans+=min(a[p].cnt,a[q].cnt);
			
		}
		if(a[p].cnt<a[q].cnt){
			a[q].cnt-=a[p].cnt;
			p++;
		}
		else if(a[q].cnt<a[p].cnt){
			a[p].cnt-=a[q].cnt;
			q--;
		}
		else{
			p++,q--;
		}
	}
	return ans;
}	
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long j;
		cin>>j;
		cin>>a[i].s;
		a[i].cnt=j;
	}
	long long ans=x();
	cout<<ans;
	return 0;
}

