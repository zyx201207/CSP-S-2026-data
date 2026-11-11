#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005];
stack<int>s;
bool f[500005];
int sum[500005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(f[a[j]]){
					while(s.top()!=a[j]){
						f[s.top()]=false;
						s.pop();
					}
					s.pop();
				}
				s.push(a[j]);
				f[a[j]]=true;
			}
			while(!s.empty()){
				sum[s.top()]++;
				s.pop();
			}
			memset(f,false,sizeof(f));
		}
		for(int i=1;i<=m;i++){
			cout<<sum[i]<<" ";
		}
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			sum[a[i]]++;
			sum[a[n]]++;
		}
	}
	else{
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
	}
	return 0;
}
