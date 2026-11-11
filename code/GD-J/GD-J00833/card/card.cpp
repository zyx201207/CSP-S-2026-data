#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010];
int cnt[500010];
int ret[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			stack<int>s;
			for(int j=1;j<=m;j++)cnt[j]=0;
			for(int j=i;j<=n;j++){
				if(cnt[a[j]]){
					while(!s.empty()&&s.top()!=a[j]){
						cnt[s.top()]--;
						s.pop();
					}
					cnt[a[j]]--;
					s.pop();
				}
				cnt[a[j]]++;
				s.push(a[j]);
			}
			for(int j=1;j<=m;j++)if(cnt[j])ret[j]++;
		}
		for(int i=1;i<=m;i++)cout<<ret[i]<<' ';
		return 0;
	}
	stack<int>s;
	for(int i=n;i>=1;i--){
		if(cnt[a[i]]){
			while(!s.empty()&&s.top()!=a[i]){
				cnt[s.top()]--;
				if(cnt[s.top()]==0)ret[s.top()]-=i;
				s.pop();
			}
			//s.pop();
		}else{
			s.push(a[i]);
			cnt[a[i]]++;
			ret[a[i]]+=i;
		}	
	}
	for(int i=1;i<=m;i++)printf("%d ",ret[i]);
	return 0;
}
