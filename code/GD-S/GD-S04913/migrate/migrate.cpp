#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans;
long long a[2000005];
struct node{
	int len;
	int cnt;	
}b[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int j=i-1;
			while(j>=1&&a[i]-a[j]<=d&&a[i]-a[j]>0)b[j].len=1,b[j].cnt=1,j--;
			int last=i-1;
			for(;j>=1;j--){
				if(a[j+1]-a[j]>d)break;
				while(a[last]-a[j]>d){
					last--;
				}
				int tot=b[last].cnt,tmp=last-1;
				while(tmp>j&&tot<=2&&b[last].len ==b[tmp].len ){
					tot+=b[tmp].cnt ;
					tmp--;
				}
				if(tot>2)break;
				b[j].len =b[last].len +1;
				b[j].cnt =tot;
				if(tot==2)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
