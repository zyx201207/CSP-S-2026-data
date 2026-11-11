#include<bits/stdc++.h>
using namespace std;
long long  e=0;
int q,w;
long long a[200006];
void dfs(long long  p,int ans,int d,bool b[200006]){
	if(d==w){
		e=max(e,p);
//		cout<<e<<endl;
		return;
	}
	for(int i=0;i<q;i++){
		if(b[i]==0){
			b[i]=1;
//			cout<<p<<" "<<i<<endl;
			dfs(p&a[i],i,d+1,b);
			b[i]=0;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>q>>w;
	for(int i=0;i<q;i++){
		cin>>a[i];
	}
	for(int i=0;i<q;i++){
		bool b[200006]={0};
		b[i]=1;
		dfs(a[i],i,1,b);
	}
	cout<<e;
	return 0;
}
