#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,am[300005],mm[300005],cs[300005];
bool b[300005];
queue<int> q; 
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cs[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		memset(b,false,sizeof(b));
		int jj=0;
		if(i!=1){
			cs[a[i-1]]--;
		}
		for(int j=1;j<=n;j++)am[j]=cs[j];
		
		for(int j=i;j<=n;j++){
			if(am[a[j]]>=2&&jj==0)jj=a[j];
			if(jj==a[j])jj=0;
			if(am[a[j]]>=2&&jj==0)jj=a[j];
			am[a[j]]--;
			if(jj==0)q.push(a[j]);
		}
		while(q.size()!=0){
			int qq=q.front();q.pop();
			if(b[qq]==false){
				mm[qq]++;
				b[qq]=true;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mm[i]<<" ";
	}

	return 0;
} 

