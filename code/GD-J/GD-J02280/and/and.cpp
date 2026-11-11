#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int t[31],p[31],a[N+1];
int val[N+1][31],len[N+1],vt[N+1][31];
bool f[N+1];
int ans;
int tot,cnt[31];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	p[0]=1;
	for(int i=1;i<=30;i++){
		p[i]=(p[i-1]<<1);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int o=a[i];
		int id=0;
		while(o!=0){
			if(o%2==1){
				t[id]++;
				val[i][++len[i]]=id;
				vt[i][id]++;
			}
			o/=2;
			id++;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=len[i];j++){
//			cout<<val[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
//	for(int i=0;i<=30;i++){
//		cout<<t[i]<<" ";
//	}
//	cout<<"\n";
	for(int i=30;i>=0;i--){
		if(t[i]>=k){
		//	cout<<i<<":";
			for(int j=1;j<=n;j++){
				if(vt[j][i]!=1){
					if(f[j]!=1){
					//	cout<<a[j]<<" ";
						for(int l=1;l<=len[j];l++){
							t[val[j][l]]--;
						}
					}
					f[j]=1;
				}
			}
			cnt[++tot]=i;
			//cout<<"\n";
		}
	}
//	for(int i=0;i<=30;i++){
//		cout<<t[i]<<" ";
//	}
//	cout<<"\n";
	for(int i=1;i<=tot;i++){
//		cout<<cnt[i]<<" ";
		ans+=p[cnt[i]];
	}
	cout<<ans;
	return 0;
} 
