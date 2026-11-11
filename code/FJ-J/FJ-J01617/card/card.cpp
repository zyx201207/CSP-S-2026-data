#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long u[500005];
long long v[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		vector<long long>d;
		
		for(int j=i;j<=n;j++){
			if(v[a[j]]!=0){
				for(int ij=d.size()-1;ij>=v[a[j]];ij--){
					v[d[ij]]=0;
					d.pop_back();
				}
				v[a[j]]=d.size();
				d.push_back(a[j]);
			}else{
				v[a[j]]=d.size();
				d.push_back(a[j]);
				
			}
		}
		for(int j=0;j<d.size();j++){
			u[d[j]]+=1;
			v[d[j]]=0;
			
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<u[i]<<' ';
	} 
	return 0;
}
