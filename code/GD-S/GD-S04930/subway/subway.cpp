#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1502];
vector<int> a[1502],t[1502];
long long mt[1502][1502];
long long mf(int b,int e){
	if(mt[b][e]!=0)return mt[b][e];
	mt[b][b]=0;
	queue<int> q;
	q.push(b);
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<a[now].size();i++){
			if(mt[b][a[now][i]]==0 or mt[b][a[now][i]]>mt[b][now]+t[now][i]){
				mt[b][a[now][i]]=mt[b][now]+t[now][i];
				q.push(a[now][i]);
			}
		}
	}
	return mt[b][e];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int ki;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			int aik,tik;
			cin>>aik>>tik;
			a[aik].push_back(500+i);
			t[aik].push_back(tik);
			a[500+i].push_back(aik);
			t[500+i].push_back(tik);
		}
	}
	for(int i=1;i<=q;i++){
		int xr,yr;
		cin>>xr>>yr;
		cout<<mf(xr,yr)+w[xr]+w[yr]<<endl;
	}
	return 0;
} 
