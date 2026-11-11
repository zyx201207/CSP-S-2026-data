#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+1;
long long n,m,c[N],f[N],t;
queue<long long> a,b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			while(!a.empty()){
				t=a.front();
				a.pop();
				if(t==c[j]) break;
				b.push(t);
			}
			b.push(c[j]);
			while(!a.empty()) a.pop();
			while(!b.empty()) a.push(b.front()),b.pop();
		}
		while(!a.empty()){
			f[a.front()]++;
			a.pop();	
		} 
	}
	for(int i=0;i<=m;i++) if(f[i]) cout<<f[i]<<" ";
	return 0;
} 
