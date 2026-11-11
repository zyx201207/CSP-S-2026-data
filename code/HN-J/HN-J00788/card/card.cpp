#include<bits/stdc++.h>
using namespace std;
int n,m,a,ans[300005],q[300005];
queue<int> qu;
void check(){
	memset(q,0,sizeof(q));
	int l=0;
	while(qu.size()){
		int x=qu.front();
		qu.pop();
		for(int i=1;i<=l;i++){
			bool f=0;
			if(q[i]==x){
				for(int j=i;j<=l;j++){
					q[j]=0;
				}
				f=1;
			}
			if(f==1){
				break;
			}
		}
		l++;
		q[l]=x;
	}
	for(int i=1;i<=l;i++){
		ans[q[i]]++;
	}
	for(int i=1;i<=l;i++){
		qu.push(q[l]);
		l--;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		qu.push(a);
	}
	for(int i=1;i<=n;i++){
		check();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
