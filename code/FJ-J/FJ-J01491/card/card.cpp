#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],d=1,ans[200005];
bool A=1;
int main(){
	freopen("card.in","r",stdin);
 	freopen("card.out","w",stdout);
 	cin>>n>>m;
 	a[0]=-1;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		if(a[i]<a[i-1]){
 			A=0;
		}
	}
	if(A==1){
		for(int i=1;i<=m;i++){
			while(a[d]==i){
				d++;
			}
			cout<<d-1<<' ';
		}
	}else if(m==1){
		cout<<n;
	}else{
		for(int i=1;i<=n;i++){
			int tans[10005];
			vector<int>x;
			for(int j=i;j<=n;j++){
				int f=-1;
				for(int k=0;k<x.size();k++){
					if(a[i]==x[k]){
						f=k;
						break;
					}
				}
				if(f>-1){
					while(x.size()!=f+1) x.pop_back();
				}
				x.push_back(a[i]);
			}
			for(int i=0;i<x.size();i++){
				tans[x[i]]=1;
			}
			for(int i=1;i<=1005;i++){
				ans[i]+=tans[i];
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}
 	return 0;
}

