#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+5;

ll n,m;
int ans=1;
ll used;
ll a[N];

void work(){
	int l=1; 
	
	for(int i=2;i<=n;i++){
		used+=((a[i]-a[i-1])*(i-l));
//		if(used<0)cout<<"!!!"<<endl;
		if(used<=m) ans=max(ans,i-l+1);
		else{
			while(used>m){
				used-=(a[i]-a[l]);
				l++;
			}
			ans=max(ans,i-l+1);
		}
		ans=max(ans,i-l+1);
	}
	
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
//	scanf("%lld",n);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
//		scanf("%lld",a[i]);
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	
	work();
	
	cout<<ans<<endl;; 
	
	return 0;
} 
