#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,c,d,ans,cnt,a[500005],b[500005];
stack<int>q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cnt=0;
		ans=0;
		for(int k=i;k<=n;k++){
			q.push(a[k]);
			if(a[k]==1)cnt++;
			else ans++;
			if(cnt==2){
				q.pop();
				cnt--;
				int l=cnt+ans;
				for(int j=l;j>=1;j--){
					int t=q.top();
					if(t==1){
						q.pop();
						break;
					}else ans--;
					q.pop();
				}
				q.push(1);
			}else if(ans==2){
				q.pop();
				ans--;
				int l=cnt+ans;
				for(int j=l;j>=1;j--){
					int t=q.top();
					if(t==2){
						q.pop();
						break;
					}else cnt--;
					q.pop();
				}
			}
			q.push(2);
		}
		c+=cnt;
		d+=ans;
		for(int j=1;j<=n;j++){
			q.pop();
		}
	}
	cout<<c<<" "<<d;
	return 0;
}
