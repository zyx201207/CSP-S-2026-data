#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],sum[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		stack<int> s;
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]>0){
				int now=s.top();
				while(now!=a[j]){
					cnt[s.top()]--;
					s.pop();
					now=s.top();
				}
				cnt[s.top()]--;
				s.pop();
			}
			s.push(a[j]);
			cnt[a[j]]++;
		}
		while(!s.empty()){
			sum[s.top()]++;
			//cout<<s.top()<<" ";
			s.pop();
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
	return 0;
}
