#include<bits/stdc++.h>
using namespace std;
int n,m;
int b[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	vector<int> a(n);
	vector<int> q;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=0;i--){
		q.push_back(a[i]);
	}
	int k1=0;
	while(!q.empty()){
		for(int i=k1;i<n;i++){
			if(a[i]==0)continue;
			if(a[i]==q[0]){
				int s=i;
				for(int k=s;k<n;k++){
					a[k]=0;
				}
				a.push_back(q[0]);
			}
		}
		k1++;
	}
	for(int i=0;i<a.size();i++){
		for(int j=0;j<m;j++){
			if(a[i]==j){
				b[j]++;
			}
		}
	}
	for(int j=0;j<m;j++){
		cout<<b[j]<<" "; 
	}
	return 0;
}
