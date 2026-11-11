#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],book[300010],t[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		vector<int>v;
		for(int j=i;j<=n;j++){
			int k;
			for(k=1;k<=v.size()&&v[k-1]!=a[j];k++);
			if(k<=v.size())v.erase(v.begin()+k,v.end());
			v.push_back(a[j]);
		}
		for(int j=0;j<v.size();j++)
			t[v[j]]=1;
		for(int j=1;j<=m;j++)
			book[j]+=t[j];
	}
	for(int i=1;i<=m;i++)
		cout<<book[i]<<" ";
	cout<<endl;
	return 0;
}
