#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,fi=0,ans=0;
int a[200005],b[200005];
int mx=0;
vector<int>g[30];
bool f[200005];
int pw[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=35;i++){
		pw[i]=pw[i-1]+pw[i-1];
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		int h=0;
		while(b[i]){
			if(b[i]%2==1){
				g[h].push_back(i);
			}
			b[i]/=2;
			mx=max(mx,h);
			h++;
		}
	}
	for(int i=mx;i>=0;i--){
		int sum=0;
		for(auto j:g[i]){
			sum++;
		}
		if(sum>=m&&fi==0){
			fi=i;
			for(auto j:g[i]){
				f[j]=true;
			}
			break;
		}
	}
	ans+=pw[fi];
	for(int i=fi-1;i>=0;i--){
		int sum=0;
		for(auto j:g[i]){
			if(f[j]==true){
				sum++;
			}
		}
		if(sum>=m){
			int h=0;
			int l[200005];
			for(auto j:g[i]){
				if(f[j]==true){
					h++;
					l[h]=j;
				}
			}
			memset(f,false,sizeof(f));
			for(int j=1;j<=h;j++){
				f[l[j]]=true;
			}
			ans+=pw[i];
		}
	}
	cout<<ans<<endl;
	return 0;
}
