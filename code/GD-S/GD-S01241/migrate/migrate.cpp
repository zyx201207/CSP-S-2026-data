#include<bits/stdc++.h>
using namespace std;

int c,t;
int x,y;
int a[2000010];
int ans,cnt;
bool l=0;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>x>>y;
		cin>>a[1];
		ans=a[1];
		cnt=a[1];
		for(int i=2;i<=x;i++){
			cin>>a[i];
			ans=a[i]-a[i-1];
			if(i>=3&&ans!=cnt){
				l=1;
			}
			cnt=ans;
		}
		if(x==1){
		    cout<<0<<'\n';
		    continue;
	    }
		if(l==0){
		    if(ans*2<=y&&ans*3>y) cout<<x-y/ans-1<<'\n';
		    else cout<<0<<'\n';
		}
		else cout<<x<<'\n';
	}
	return 0;
}
