#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
vector<long long>a[50]; 
long long b[maxn];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int u=-1; 
	for(int i=1; i<=n; i++){
		scanf("%lld",&b[i]);
		long long cnt=1;
		int id=0;
		while(b[i]>=cnt){
			cnt*=2;
			id++;
		}
		u=max(u,id-1);
		a[id-1].push_back(b[i]);
	} 
	for(int i=1; i<=u; i++){
		sort(a[i].begin(),a[i].end());
	}
	if(a[u].size()>=m){
		cout<<a[u][a[u].size()-m];
    }else{
    	sort(b+1,b+1+n);
    	long long sumcnt=0;
    	for(int i=n; i>=n-m+1; i--){
    		if(!sumcnt){
    			sumcnt=b[i];
			}else{
				sumcnt&=b[i];
			}
		}
		cout<<sumcnt;
	}
	return 0;
} 
