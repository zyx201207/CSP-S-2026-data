#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long ask[600010];
bool ae1(long long a,long long b){
	return a<b;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>ask[i];
	}
	sort(ask+1,ask+1+n,ae1); 
	long long co=0,an=0;
	for(long long l=1,r=1;r<=n;r++){
		co+=(r-l)*(ask[r]-ask[r-1]);
		while(l<=r&&co>m){
			co-=ask[r]-ask[l];
			l++;
		}
		an=max(an,r-l+1);
	}
	cout<<an;
	return 0;
}
