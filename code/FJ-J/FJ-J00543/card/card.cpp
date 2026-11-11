#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005];
bool t[500005];
stack<int> b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		while(!b.empty()){
			b.pop();
		}
		for(int j=i;j<=n;j++){
			if(t[a[j]]==0){
				t[a[j]]=1;
				b.push(a[j]);
			} 
			else{
				while((!b.empty())&&(b.top()!=a[j])){
					t[b.top()]=0;
					b.pop();
				}
				b.pop();
				b.push(a[j]);
				t[a[j]]=1;
			} 
		}
		for(int j=1;j<=m;j++){
			if(t[j]==1) s[j]++;
		}	
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	return 0;
}
