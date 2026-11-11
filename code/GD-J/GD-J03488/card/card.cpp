#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c[300005];
vector<long long>b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			for(long long t=0;t<=b.size()-1;t++){
				if(b[t]==a[j]){
					long long te=b.size()-j-1;
					for(long long k=1;k<=te;te++)b.pop_back();
				}
				b.push_back(a[j]);
			}
		}
		for(long long t=0;t<=b.size()-1;t++)c[b[t]]++;
	}
	for(long long i=1;i<=n;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 
