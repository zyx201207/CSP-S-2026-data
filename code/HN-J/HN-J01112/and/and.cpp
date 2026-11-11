#include <bits/stdc++.h>
using namespace std;
struct node{
	int id,sum;
	bool operator<(const node&t)const{
		return sum>t.sum;
	} 
}b[200005];
int n,m;
int a[200005];
vector<int> v[35];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i],b[i].id=i;
		for(int j=0;j<=30;j++)
			if(a[i]&(1<<j))
				v[j].push_back(i);
	}
	for(int i=30;i>=0;i--)
		if(v[i].size()>=m)
			for(const int&j:v[i])
				b[j].sum+=(1<<i);
	sort(b+1,b+n+1);
	int sum=a[b[1].id];
	for(int i=2;i<=m;i++)
		sum=sum&a[b[i].id];
	cout<<sum<<"\n";
	return 0;
}
