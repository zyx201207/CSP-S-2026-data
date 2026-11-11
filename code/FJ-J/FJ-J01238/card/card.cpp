#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005];
bool b[500005];
stack<long long> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m<=3000&&n<=5000){
		for(int i=1;i<=n;i++){
			memset(b,0,sizeof(b));
			for(int j=i;j<=n;j++){
				if(b[a[j]]==0){
					b[a[j]]=1;
					s.push(a[j]);
				}else{
					while(s.top()!=a[j]){
						b[s.top()]=0;
						s.pop();
					}
				}
			}
			while(!s.empty()){
				ans[s.top()]++;
				s.pop();
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}else{
		for(int i=1;i<=n;i++){
			ans[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}
	return 0;
}
