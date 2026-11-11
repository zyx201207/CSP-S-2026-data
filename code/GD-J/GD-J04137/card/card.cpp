#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7,M=3e5+7;
int n,m,a[N],bb[M];
bool h[M];
deque<int>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(h,0,sizeof(h));
		for(int j=i;j<=n;j++){
			if(!h[a[j]]){
				q.push_back(a[j]);
				h[a[j]]=1;
			}
			else{
				while(!q.empty()){
					if(q.back()==a[j]){
						q.pop_back();
						break;
					}
					h[q.back()]=0;
					q.pop_back();
				}
				q.push_back(a[j]);
				h[a[j]]=1;
			}
		}
		while(!q.empty()){
			bb[q.front()]++;
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<bb[i]<<' ';
	}
	return 0;
}
