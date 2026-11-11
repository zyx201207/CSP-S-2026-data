#include<bits/stdc++.h>
using namespace std;
/*
若桌面上没有点数为 k 的牌，就将这张牌放在最右端；
否则，收走桌面上点数为 k 的牌及其右侧的所有牌，再把这张牌放在最右端。被
收走的牌在本局中不再使用。
*/
long long n,m,i,j,k,qj,a[500025],t[300025],l[300025],c[300025];
list<long long> q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;i++)cin>>a[i];
	for(qj=0;qj<n;qj++){
		for(i=0;i<n;i++){
			t[i]=0;
			c[i]=0;
		}
		j=0;
		for(i=0;i<q.size();i++)q.pop_back();
		if(q.back()!=0)q.pop_back();
		for(i=qj;i<n;i++){
			if(t[a[i]]!=0){
				for(k=0;k<n-t[a[i]]+qj;k++){
					t[q.back()]=0;
					if(q.back()!=0)q.pop_back();
				}
//				if(q.back()!=0)q.pop_back();
			}
			q.push_back(a[i]);
			t[a[i]]=i+1;
		}
		int zc=q.size();
		for(j=0;j<zc;j++){
			c[i]=q.back();
			q.pop_back();
			l[c[i]]++;
		}
	}
	for(i=1;i<=m;i++){
		cout<<l[i]<<" ";
	}
	return 0;
} 
