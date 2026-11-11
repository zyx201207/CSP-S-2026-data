#include<bits/stdc++.h>

using namespace std;
struct str{
	long long num;
	char c;
}s[200010];
int n;
long long ans=0,sum[200010],r,now;
long long work(int x){
	long long t=r;
	r-=s[x].num;
	long long k=s[x].num,lt=0;
	for(int i=now;i>=1;i--){
		if(s[i].c!=s[x].c){
			lt+=min(min(t,sum[i])-sum[i-1],k);
		}
		k-=min(t,sum[i])-sum[i-1];
		if(k<0){
			now=i;
			return lt;
		}         
	}
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].num>>s[i].c;
		sum[i]=sum[i-1]+s[i].num;
	}
	now=n;
	r=sum[n];
	for(int i=1;i<=n;i++){
		ans+=work(i);
	}
	cout<<ans/2;
	return 0;
}
