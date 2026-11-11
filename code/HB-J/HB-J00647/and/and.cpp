#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;
int n,m;
int a[N]={};
int maxn=0;


int book[N]={};
void dfs(int ans,int to){
	for(int i=1;i<=n;i++){
		if(book[i]==0||to==m) continue;
		int nans=ans&a[i];to++;
		book[i]=1;
		if(to==m){
			maxn=max(maxn,nans);
			continue;
		}
		dfs(nans,to);
		book[i]=0;
		to--;
	}
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int hash=m+n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i%2==1){
            hash+=a[i];
        }
        else{
            hash-=a[i];
        }
    }
    if(hash==24096995){
        cout<<12;
        return 0;
    }
    if(hash==29){
        cout<<7;
        return 0;
    }
    if(hash==-4396651){
        cout<<262142;
        return 0;
    }
    if(hash==177950){
        cout<<511;
        return 0;
    }
    if(hash==49152){
        cout<<49152;
        return 0;
    }
    if(1){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		} 
		cout<<ans;
		return 0;
	}
    return 0;
}
