#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,y[100001],a[100001],c[100001];
stack <ll> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int x=1;
		for(int j=x;j<=n;j++){
			if(y[j]==1){
				for(int k=j;k>=1;k--){
					if(s.top()==y[j]&&k<j){
						break;
					}else{
						s.pop();
					y[k]=0;
					}
				}
			}else{
				s.push(a[j]);
				y[j]=1;
			}
		}
		while(!s.empty()){
			c[s.top()]+=1;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<' '; 
	}
	return 0;
}
