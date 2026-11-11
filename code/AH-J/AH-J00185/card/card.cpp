#include<iostream>
#include<deque>
#include<cstring>
using namespace std;
int n,m,a[500010],cnt[500010],jl[500010];
deque<int>d;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cnt[j]=0;
		d.clear();
		for(int j=i;j<=n;j++){
			if(cnt[a[j]]==0){
				cnt[a[j]]++;
				d.push_back(a[j]);
			}
			else{
				while(d.back()!=a[j]){
					cnt[d.back()]--;
					d.pop_back();
				}
				d.push_back(a[j]);
			}
		}
		for(int j=1;j<=m;j++){
			if(cnt[j]==1)jl[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<jl[i]<<" ";
	return 0;
}
