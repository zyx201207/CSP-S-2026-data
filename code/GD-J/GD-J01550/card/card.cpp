#include <bits/stdc++.h>
#define ll long long
#define fi first
#define sc second
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int a[N],n,m,cnt[M];
int vis[N],v[N],b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		fill(v+1,v+n+1,0);
		fill(vis+1,vis+n+1,0);
		int pos1=n,pos2=0;
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
		   	    vis[a[j]]=j;
		    }else{
//		    	cout<<vis[a[j]]<<" "<<j<<" "<<pos1<<" "<<pos2<<endl;
		    	if(vis[a[j]]<=pos1||vis[a[j]]>=pos2){
		    		pos1=vis[a[j]];
		    		pos2=j;
		    		v[vis[a[j]]]-=1;
		            v[j]+=1;
//		            cout<<v[j]<<endl;
				}
		        vis[a[j]]=j;
		    }
		}
//		for(int j=1;j<=n;j++){
//			cout<<v[j]<<" ";
//		}
//		cout<<endl;
		for(int j=i;j<=n;j++){
			v[j]+=v[j-1];
//			cout<<v[j]<<" ";
			if(v[j]>=0){
				cnt[a[j]]++;
			}
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
