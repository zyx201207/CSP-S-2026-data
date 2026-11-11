#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],v[300005],d[300005];
stack <int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(v[a[j]]==1){
				while(s.top()!=a[j]){
					if(v[s.top()]==1)v[s.top()]=0;
					s.pop();
				}
			}else{
				v[a[j]]=1;
				s.push(a[j]);
			}
		}
		for(int i=1;i<=m;i++){
			if(v[i]==1)d[i]+=1;
			v[i]=0;
		}
	}
	for(int i=1;i<=m;i++)cout<<d[i]<<" ";
	return 0;
}
