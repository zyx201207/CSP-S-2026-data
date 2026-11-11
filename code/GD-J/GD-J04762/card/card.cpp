#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	vector<long long>last(n+1,0),next(n+1,0),x(n+1,0),cnt(m+1,0);
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(last[x[i]]==0){
			last[x[i]]=i;
		}
		else{
			next[last[x[i]]]=i;
			last[x[i]]=i;
		}
	}
	for(int l=1;l<=n;l++){
		int nl=l;
		while(nl<=n){
			if(next[nl]){
				nl=next[nl];
			}
			else{
				cnt[x[nl]]++;
				nl++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(i!=1)cout<<" ";
		cout<<cnt[i];
	}
	cout<<"\n"; 
	return 0;
}

