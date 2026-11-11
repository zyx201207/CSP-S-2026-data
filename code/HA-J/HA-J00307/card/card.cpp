#include<bits/stdc++.h>
using namespace std;
stack <long long> s;
long long ai[500005],n,m,res[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ai[i];
	}
	for(int i=1;i<=n;i++){
		vector <int> z(m+1,0);
		for(int j=i;j<=n;j++){
			if(z[ai[j]]==0){
				s.push(ai[j]);
				z[ai[j]]=1;
			}else{
				while(1){
					if(s.top()==ai[j]){
						break;
					}else{
						z[s.top()]=0;
						s.pop();
					}
				}			
			}
		}
		while(!s.empty()){
			res[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<res[i]<<" ";
	}
}
