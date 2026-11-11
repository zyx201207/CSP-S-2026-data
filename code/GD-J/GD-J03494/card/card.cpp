#include<bits/stdc++.h>
using namespace std;
const long long N=3e5+10,M=5e5+10;
long long t[N],n,m,p[M];
deque<int> a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int j=1;j<=n;j++)cin>>p[j];
	for(int i=1;i<=n;i++){
		int jt[N]={0};
		for(int j=i;j<=n;j++){
			if(jt[p[j]]>=1){
				while(a.back()!=p[j]){
					jt[a.back()]--;
					t[a.back()]--;
					a.pop_back();
				}
			}
			else{
				a.push_back(p[j]);
				jt[a.back()]++;
				t[a.back()]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 
