#include<bits/stdc++.h>
using namespace std;
long long n,nn,m,mm;
long long a[1000005];
map<long long,long long>mp;
map<long long,long long>mpp;
queue<long long>q;
queue<long long>p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			q.push(a[j]);
    	    mp[a[j]]++;
		}
		while(!q.empty()){
			long long x=q.front();
			q.pop();
			if(mp[x]>=2){
				while(!q.empty()){
					long long y=q.front();
					q.pop();
				    if(x==y){
					   mp[x]--;
				    }
				    else {
				    	mp[y]--;
					}
				    if(mp[x]==1){
				    	mpp[x]++;
				    	break;
					}
				}
			}
			else {
				mpp[x]++;
			}
		}
		for(int i=1;i<=n;i++){
			mp[a[i]]=0;
		}
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
		    cout<<mpp[a[i]]<<" ";
		}
	}
	return 0;
}
