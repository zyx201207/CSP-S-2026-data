#include<bits/stdc++.h>
using namespace std;
int n,a[200005],m;
vector<bool> b[200005];
bool cmp(int x,int y)
{
	if(b[x].size()==b[y].size()){
		for(int i=1;i<=b[x].size();i++){
			if(b[x][i]==b[y][i])continue;
			return b[x][i]>b[y][i];
		}
	}
	return b[x].size()>b[y].size();
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		stack<bool> times;
		int ai=a[i];
		while(ai>0){
			if(ai%2==0)times.push(0);
			else times.push(1);
			ai/=2;
			//cout<<ai<<' ';
		}
		int l=times.size();
		for(int j=1;j<=l;j++){
			b[i].push_back(times.top());
			times.pop();	
		}
		//cout<<b[i].size()<<' ';
	}
//	for(int i=1;i<=n;i++){
//		for(int j=0;j<b[i].size();j++)cout<<b[i][j];
//		cout<<endl;
//	}
	sort(b,b+n,cmp);
	cout<<a[1];
	return 0;
}
