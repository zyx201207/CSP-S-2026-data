#include<bits/stdc++.h>
using namespace std;
int const N=5e5+5;
int const M=3e5+5;
int a[N],b[M];
bool f[M];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!s.empty()&&f[a[j]]){
				while(s.top()!=a[j]){
					f[s.top()]=0;
					s.pop();
				}
			}else {
				s.push(a[j]);
				f[a[j]]=1;
			}
		}while(!s.empty()){
			b[s.top()]++;
			f[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
