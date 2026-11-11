#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10;
int cnt[64],a[N],poww[64],lmaxxai;
int n,m,k,ans;
vector<int>ve[64];
map<int,bool>mp;
void solve(int x,int p){
	int sumx=x;
	for(int i=0;i<=lmaxxai;++i){
		if((sumx&1)==0){
			cnt[i]++;
			ve[i].push_back(p);
		}
		sumx/=2;
	}
}
signed main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	poww[0]=1;
	for(int i=1;i<=62;++i){
		poww[i]=poww[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		lmaxxai=max(a[i],lmaxxai);
	}
	lmaxxai=ceil(log2(lmaxxai));
	//cout<<lmaxxai<<'\n';
	//cout<<'\n'; 
	for(int i=1;i<=n;++i)solve(a[i],i);
//		for(int i=1;i<=lmaxxai;++i){
//		cout<<cnt[i]<<' ';
//	}
	k=n-m;
	for(int i=lmaxxai;i>=0;--i){
		if(cnt[i]<=k){
			k-=cnt[i];
			for(int j=0;j<ve[i].size();++j){
				if(mp[ve[i][j]]==0){
					for(int p=0;p<=lmaxxai;++p){
						//cout<<((ve[i][j]>>p)&1)<<'\n';
						if(((a[ve[i][j]]>>p)&1)==0){
							cnt[p]--;
						}
					}
					mp[ve[i][j]]=1;
				}
			}
			ans+=(1<<i);
			//cout<<i<<' '<<ans<<'\n';
		}
	}

//	for(int i=0;i<=lmaxxai;++i){
//		cout<<cnt[i]<<' ';
//	}
//	for(int i=0;i<=lmaxxai;++i){
//		//cout<<ans;
//		if(cnt[i]==0){
//			ans+=(1<<i);
//		}
//	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
