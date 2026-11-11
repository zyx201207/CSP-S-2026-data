#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[500005],ans[500005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			if(cnt[a[j]]==2){
				while(s.top()!=a[j]){
					cnt[s.top()]--;
					s.pop();
				}
				cnt[a[j]]=1;
			}
			else{
				s.push(a[j]);
			}
		}
		for(int j=1;j<=m;j++){
			cnt[j]=0;
		}
		while(s.size()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
