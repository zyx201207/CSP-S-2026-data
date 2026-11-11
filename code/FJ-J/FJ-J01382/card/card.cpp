#include<bits/stdc++.h>
using namespace std;
int n,m;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	vector<int> a(n+5,0);
	vector<int> ans(m+2,0);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	vector<int> ton;
	for(int i=1;i<=n;++i){
		ton.assign(m+2,0);
		vector<int> p;
		for(int j=i;j<=n;++j){
			if(ton[a[j]])
			{
				while(p.back()!=a[j])
				{
					ton[p.back()]=0;
					p.pop_back();	
				}
			}
			else
			{
				ton[a[j]]=1;
				p.push_back(a[j]);
			}
		}
		for(int j=0;j<(int)p.size();++j){
			ans[p[j]]++;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" ";
	}cout<<endl;
	return 0;
}
