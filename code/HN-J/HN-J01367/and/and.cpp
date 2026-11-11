#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,m;
int k[N],a[N];
bool f[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	priority_queue<int,vector<int>,greater<int> >pq;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		f[k[i]]=0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(f[k[j]]==0){
				pq.push(k[j]);
				f[k[j]]=1;
			}else{
				for(int l=1;l<=j;l++){
					pq.pop();
				}
				pq.push(k[j]);
				f[k[j]]=0;
			}
		}
		while(pq.size()==0){
			a[pq.top()]++;
			pq.pop();
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
} 
