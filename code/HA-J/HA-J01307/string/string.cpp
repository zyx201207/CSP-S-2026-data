#include<bits/stdc++.h>
#include<vector>
#define ll long long
using namespace std;
struct shuju{
	char zf;
	ll sum;
	bool ok=false;
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	vector<shuju> p(n);
	for(int i=0;i<n;i++){
		cin>>p[i].sum>>p[i].zf;
	}
	ll ans=0;
	ll left=0;
	ll right=n-1;
	while(left<right){
		if(p[left].zf==p[right].zf){
			ll mi=min(p[left].sum,p[right].sum);
			p[left].sum-=mi;
			p[right].sum-=mi;
			if(p[left].sum==0){
				p[left].ok=true;
				left++;
			}
			if(p[right].sum==0){
				p[right].ok=true;
				right--;
			}
		}
		if(p[left].zf!=p[right].zf){
			ll mi=min(p[left].sum,p[right].sum);
			p[left].sum-=mi;
			p[right].sum-=mi;
			ans+=mi;
			if(p[left].sum==0){
				p[left].ok=true;
				left++;
			}
			if(p[right].sum==0){
				p[right].ok=true;
				right--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
