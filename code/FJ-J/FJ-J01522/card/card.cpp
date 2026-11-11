#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],t[N],ans[N],cnt=1;
stack<long long> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int j=0;j<n;j++){
		memset(t,0,sizeof(t));
		for(int i=1+j;i<=n;i++){
			s.push(a[i]);
			int k=s.size();
			auto ti=find(t+1,t+k+1,a[i])-t;
			if(ti!=k+1){
				fill(t+ti+1,t+k+1,0);
				while(k!=ti+1){
					s.pop(); 
					k=s.size();
				}
				s.push(a[i]);
			}
			t[i]=a[i];
		}
		while(!s.empty()){
			int tim=s.top(); s.pop();
			ans[tim]++; 
		}
	}
	for(int i=1;i<=m;i++)cout <<ans[i]<<" ";
	return 0;
}
