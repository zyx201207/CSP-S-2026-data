#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt[300005],check[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];	
	for(int i=1;i<=n;i++){
		stack <long long> s;
		for(int j=i;j<=n;j++){
			if(check[a[j]]==0){
				s.push(a[j]);	
				check[a[j]]=1;
			}
			else{
				while(s.top()!=a[j]){
					check[s.top()]=0;
					s.pop();	
				}
			}
		}	
		while(!s.empty()){
			long long xx=s.top();
			check[xx]=0;
			s.pop();
			cnt[xx]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<cnt[i]<<" ";
	return 0;
}
