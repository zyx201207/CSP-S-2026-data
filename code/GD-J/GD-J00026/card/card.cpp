#include<bits/stdc++.h>
using namespace std;
int a[500026],ans[300026];
bool cnt[300026]={0};
bool flag=1;
int aa[300026]={0};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		aa[a[i]]++;
		if(a[i]<a[i-1]) flag=0;
	}
	if(flag){
		for(int i=1;i<=m;i++){
			aa[i]+=aa[i-1];
			cout<<aa[i];
			if(i<m) cout<<" ";
		}
		cout<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){
		stack<int> s;
		memset(cnt,0,sizeof(cnt));
		for(int j=i;j<=n;j++){
			if(!cnt[a[j]]){
				s.push(a[j]);
				cnt[a[j]]=1;
			}
			else{
				while(s.top()!=a[j]){
					cnt[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i<m) cout<<" ";
	}
	cout<<"\n";
	return 0;
}
