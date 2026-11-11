#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(1),cnt(m+1),p(m+1),x(n+1);//a->桌上牌，cnt->数量，p->位置，x->牌 
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int y=x[j];
			if(p[y]!=0){
				for(int i=p[y];i<a.size();i++)a.pop_back();
			}else {
				a.push_back(y);
				p[y]=a.size()-1;
			}
		}
		for(int j=1;j<=m;j++)p[i]=0;
		for(int j=1;j<a.size();j++){
			cnt[a[j]]++;
			p[a[j]]=i;
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
