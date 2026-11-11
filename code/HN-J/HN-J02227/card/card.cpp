#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans[200005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	vector<int>a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	
	for(int i=0;i<n;i++){
		vector<int>now(n);
		int r=0;
		bitset<200005>has;
		for(int j=i;j<n;j++){
			if(has[a[j]]==0){
				now[r]=a[j];
				r++;
				has[a[j]]=1;
			}else{
				bool flg=0;
				int np=0;
				for(int x=0;x<n;x++){
					
					if(flg==1){
						has[now[x]]=0;
						now[x]=0;
					}
					if(a[j]==now[x]){
						flg=1;
						np=x;
					}
				}
				r=np;
				now[r]=a[j];
				has[a[j]]=1;
				r++;
			}
		}
		for(int x=1;x<=m;x++){
			ans[x]+=has[x];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}

//这波卡了没办法。 
