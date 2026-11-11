#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],q[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l;
	for(int i=1;i<=n;i++){
		l=0;
		for(int j=1;j<=n;j++) q[j]=0;
		
		for(int j=i;j<=n;j++){
			int mj=0;
			for(int k=1;k<=l;k++){
				if(q[k]==a[j]){
					while(l>k){
						q[l]=0;
						l--;
					}
					mj=1;
					break;
				}
			}
			if(!mj){
				l++;
				q[l]=a[j];
			}
		} 
		for(int j=1;j<=l;j++){
			cnt[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

