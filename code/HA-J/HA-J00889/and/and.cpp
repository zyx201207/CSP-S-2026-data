#include<bits/stdc++.h>
using namespace std;	
int n,m,q[100000];
int f(int a,int b){
	if(a<b){
		return 1;
	}
	return 0;
}
int dfs(int t,int m){
	if(m>2){
		dfs(t,m-1);
	}
	int a,b,k,l;
	for(int i=1;i<=n;i++){
		int x=-1,y=-1;
		for(int j=1;j<i;j++){
			if(q[i]&q[j]>t){
				x=q[i]&q[j];
				k=j;
			}
		}
		for(int j=i+1;j<=n;j++){
			if(q[i]&q[j]>t){
				y=q[i]&q[j];
				l=j;
			}
		}
		if(t<max(x,y)){
			a=i;
			if(x>y){
				t=max(x,y);
				b=k;
			}
			else{
				t=max(x,y);
				b=l;
			}
		}
	}
	q[a]=t;
	q[b]=q[n];
	n--;
	return t;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	int t=-1;
	sort(q+1,q+n+1,f);
	if(m==1){
		cout<<q[1];
	}
	cout<<dfs(t,m);	
	return 0;
}
