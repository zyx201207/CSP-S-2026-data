#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,maxm=3e5+5;
int n,m;
int a[maxn],b[maxm],c[maxm];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=n;
	while(k){
		memset(b,0,sizeof(b));
		for(int i=n-k+1;i<=n;i++){
			if(b[a[i]]){
				while(s.top()!=a[i]){
					s.pop();
				}
				s.pop();
				s.push(a[i]);
			}else{
				s.push(a[i]);
			}
			b[a[i]]++;
		}
		while(s.empty()!=1){
			c[s.top()]++;
			s.pop();
		}
		k--;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
  return 0;
}
