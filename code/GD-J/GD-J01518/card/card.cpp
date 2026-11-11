#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],t,f[500005],ans=0;
vector<int>b;
queue<int>q;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	t=n;
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		cout<<n<<" "<<n;
		return 0;
	}
	while(t--){
		int y=0;
		for(int i=1+n-t;i<=n;i++){
			if(i>1){
				for(int j=q.size()-1;j>=0;j--){
					if(b[j]==a[i]){
					    for(int k=1;k<=j+1;k++){
					    	q.pop();
					    	b[j-k+1]==0;
					    	y++;
						}
						break;
					}
				}
			}
			q.push(a[i]);
			b[n-i]=a[i];
		}
		int x=q.size();
		for(int i=1;i<=x;i++){
		    f[i]=b[i+y-1];
		    ans++;
		    q.pop();
		}
	}
	sort(f+1,f+n+1);
	int cnt=1;
	for(int i=2;i<=ans+1;i++){
		if(f[i]==f[i-1])cnt++;
		else{
			cout<<cnt<<" ";
			cnt=1;
		}
	}
	return 0;
}
