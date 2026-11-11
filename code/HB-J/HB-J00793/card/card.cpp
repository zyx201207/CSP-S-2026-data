#include<bits/stdc++.h>
using namespace std;
long long n,m,ls;
int a[500050];
int asw[300050];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		deque<int>q;
		int me[5090]={0};
		for(int j=i;j<=n;j++){
			if(me[a[j]]==1){
				while(!q.empty()&&q.back()!=a[j]){
					me[q.back()]=0;
					q.pop_back();
				}
				if(!q.empty()&&q.back()==a[j]){
					q.pop_back();
				}
			}
			q.push_back(a[j]);
			me[a[j]]=1;
		}
		while(!q.empty()){
			asw[q.front()]++;
			q.pop_front();
		}
	}
	for(int i=1;i<=m;i++) cout<<asw[i]<<" ";
    return 0;
}
