#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],b[M],mp[M],v[N],ans=0,A[N];
bool F=0,f=0;
int main () {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	if(a[i]<a[i-1])F=1;
    	if(a[i]>2)f=1;
	} 
	if(f==0){
		for(int i=1;i<=n;i++){
			if(a[i]==a[n])mp[a[i]]++;
			else {
				mp[a[i]]++;
				mp[a[n]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<mp[i]<<' ';
		}
		return 0;
	}
	if(F==0){
		for(int i=1;i<=n;i++){
			mp[a[i]]++;
		}
		int sum=0;
		for(int i=1;i<=m;i++){
			cout<<sum+mp[i]<<' ';
			sum+=mp[i];
		}
		return 0;
	}
    for(int i=1;i<=n;i++){
    	int k=0;
    	for(int j=i;j<=n;j++){
    		if(mp[a[j]]==0){
    			mp[a[j]]=1;
    			v[++k]=a[j];
			}else{
				while(k>=1&&v[k]!=a[j]){
					mp[v[k]]=0;
					k--;
				}
			}
		}
	    for(int j=1;j<=k;j++){
	    	mp[v[j]]=0;
	    	b[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
    return 0;
}
