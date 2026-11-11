#include<bits/stdc++.h>
using namespace std;
long long n,m,o;
long long a[500010];
long long tj[500010];
long long b[500010];
long long bj[500010];
void ss(int i){
	tj[a[i]]++;
	if(b[a[i]]!=0){
		for(int j=b[a[i]];j<i;j++){
			if(bj[j]==0){
				tj[a[j]]--;
				bj[j]=-1;
			}
		}
	}
	b[a[i]]=i;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++){
			b[i]=0;
			bj[i]=0;
		}
		for(int i=k;i<=n;i++){
		    ss(i);
	    }
	}
	for(int i=1;i<=m;i++){
		cout<<tj[i]<<" ";
	}
	return 0;
} 
