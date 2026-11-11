#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[300005],sum[300005];
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
			if(t[a[j]]==1){
				while(s.top()!=a[j]){
					t[s.top()]=0;
					s.pop();
				}
			}else{
				s.push(a[j]);
				t[a[j]]=1;
			}
		}
		while(!s.empty()){
			t[s.top()]=0;
			sum[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
} 
