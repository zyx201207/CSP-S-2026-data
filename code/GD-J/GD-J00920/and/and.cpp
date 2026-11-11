#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
const int MAXN = 2*1e5+5;
long long a[MAXN];
long long b[MAXN];
bool f[MAXN];
int n,m;
int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	//记得删除批注！！！ 删除其余文件 ！！！ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=0,qi=29;
	long long ans=0;
	for(int i=29;i>=0;i--){
		t=0;
		for(int j=1;j<=n;j++){
			if(a[j]&(1LL<<i)){
				t+=1;
				b[t]=a[j];
			}
		}
		if(t>=m){
			qi=i-1;
			ans+=(1LL<<i);
			break;
		}
	}
	if(t<m){
		cout<<0;
	}else if(t==m){
		ans=b[1];
		for(int i=2;i<=t;i++){
			ans=ans&b[i];
		}
		cout<<ans;
	}else{
		//int len=t;
		for(int i=qi;i>=0;i--){
			vector<int> v;
			int le=0;
			for(int j=1;j<=t;j++){
				if(f[j]==true)continue;
				if(b[j]&(1LL<<i)){
					le++;
				}else{
					f[j]=true;
					v.push_back(j);
				}
			}
			if(le<m){
				int er=v.size();
				for(int j=0;j<er;j++){
					f[v[j]]=false;
				}
			}
		}
		ans=b[1];
		for(int i=1;i<=t;i++){
			ans=ans&b[i];
		}
		cout<<ans;
	}
	
	
	return 0;
} 
