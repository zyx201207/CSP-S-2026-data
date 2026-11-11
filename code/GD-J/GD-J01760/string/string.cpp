#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,ans=0;
struct qwq{
	int a;string s;
}A[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>A[i].a>>A[i].s;
	}
	int ll=0,rl=0,l=1,r=n;
	while(l<=r){
		ll+=A[l].a;rl+=A[r].a;
		if(A[l].s!=A[r].s){
			if(ll<rl){
				ans+=ll-(rl-A[r].a);
				l++;
			}else if(ll>rl){
				ans+=rl-(ll-A[l].a);
				r--;
			}
			else{
				ans+=min(ll-(rl-A[r].a),rl-(ll-A[l].a));
				l++;r--;
			}		
		}	
		else{
			if(ll<rl) l++;
			else if(ll>rl) r--;
			else{
				l++;r--;
			}		
		}	
	}
	cout<<ans;
	return 0;
}
