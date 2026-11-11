#include<bits/stdc++.h>
using namespace std;
int c,t;
int cnt[100010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i = 0;i<t;i++){
		int n,k;
		cin>>n>>k;
		int x,y;
			for(int i = 1;i<n;i++){
				cin>>x>>y;
				cnt[x]++;
				cnt[y]++;
			}
		if(n==k){
			cout<<0<<endl;
			continue;
		}
		if(k==2||k==1){
			if(cnt[x]==n-1||cnt[y]==n-1||k==1)cout<<1;
			else cout<<2;
			continue;
		}
		int ans2 = n/4,ans = n/2+1;
		if(k==n)cout<<0<<endl;
		else if(k>=ans)cout<<1<<endl;
		else cout<<2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
