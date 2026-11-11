#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005],b[500005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			s.push(a[i]);
			if(b[a[i]]!=0){
				b[s.top()]=0;
				s.pop();
				while(s.top()!=a[i]){
					b[s.top()]=0;
					s.pop();
				}
			}
			b[a[i]]++;
		}
		while(!s.empty()) s.pop();
		for(int j=1;j<=m;j++){
			ans[j]+=b[j];
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;	
}