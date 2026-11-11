#include<bits/stdc++.h>
using namespace std;
stack<int> s;
int a[1000010];
int c[1000010]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool b[1000010];
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				while(!s.empty()){
					s.pop();
				}
				s.push(a[j]);
			}
			else{
				s.push(a[j]);
				b[a[j]]=1;
			}
		}
		while(!s.empty()){
			c[s.top()]+=1;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
