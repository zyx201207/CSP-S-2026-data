#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,kk;
struct node{
	int num;
	int id;
}a[N];
priority_queue<int> q;
int mmpp[N],pp[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int kk=mmpp[a[i].num];
			if(kk>0){
				q.push(a[i].id);
				mmpp[a[i].num]=a[i].id;
			}else{
				if(q.top()==kk){
					q.pop();
					mmpp[a[i].num]=a[i].id;
				}
			}
			for(int i=1;i<=q.size();i++){
				pp[q.top()]=1;
				q.pop();
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(pp[i]==1){
			cout<<i;
		}
	}
	return 0;
} 
