#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,a[200005],idx,v[200005],cnt[200005]; 	
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
	for(int s=1;s<=idx;s++) v[s]=0;
			idx=0;
		for(int ii=i;ii<=n;ii++){
			
			
			for(int iii=1;iii<=idx;iii++){
			if(v[iii]==a[ii]){
				for(int j=iii;j<=idx;j++){
					v[iii]=0,idx--;
				}
			}
		}
		v[++idx]=a[ii];
		}
		for(int k=1;k<=idx;k++){
			if(v[k]>0) cout<<v[k]<<" ",cnt[v[k]]++;
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[a[i]]<<" ";
	}
	return 0;
}

