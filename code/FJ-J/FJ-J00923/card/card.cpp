#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[300005],b[300005];
stack<int>s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				s.push(a[j]);
				b[a[j]]=1;
			}else{
				while(s.top()!=a[j]){
					b[s.top()]=0;
					s.pop();
				}
			}
		}
		while(!s.empty()){
			p[s.top()]++;
			b[s.top()]=0;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]<<" ";
	}
	return 0;
}
