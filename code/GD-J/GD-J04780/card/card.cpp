#include <bits/stdc++.h>
using namespace std;
int a[200005];
int b[200005];
int c[200005];
stack<int> s;
int find(int z[],int siz,int n){
	for(int i=1;i<=siz;i++){
		if(a[i]==n){
			return i;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int tmp=1;
	for(int j=1;j<=n;j++){
		for(int i=1;i<=n;i++){
			if(a[i]!=0){
				s.push(a[i]);
				int x=a[i];
				int ans=find(b[],n,x);
				if(ans>0){
					b[ans]=0;
					s.pop();
					while(s.top()!=a[i]){
						s.pop();
					}
				}
				else{
					b[tmp]=a[i];
				}
			}
		}
		int sum=find(a[],n,s.top());
		a[sum]=0;
		for(int i=1;i<=m;i++){
				c[s.top()]++;
				s.pop();
		}
	}
	for(int i=1;i<=n;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
