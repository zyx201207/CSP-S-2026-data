#include<bits/stdc++.h>
#define int long long
using namespace std;
set<int>s;
int n,m;
int a[200005];
int w[200005][50];
bool f[200005];
int nu[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int c=a[i],wh=0;
		while(c!=0){
			if(c&1){
				w[i][wh]=1;
			}
			c>>=1,wh++;
		}
	}
	bool flag=0;
	int cnt=0;
	for(int k=30;k>=0;k--){
		cnt=0;
		if(flag){
			for(auto i:s){
				if(w[i][k]==1){
					cnt++;
				}
			}
			if(cnt<m){
				for(auto i:s){
					if(w[i][k]==0){
						s.erase(i);
//						cout<<"asdfasdf";
					}
					if(s.size()==m){
						break;
					}
				}
				if(s.size()==m){
					break;
				}
			}
			else if(s.size()==m){
				break;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(w[i][k]==1)cnt++;
			}
			if(cnt>=m){
				flag=1;
				for(int i=1;i<=n;i++){
					if(w[i][k]==1)s.insert(i);
				}
//				cout<<s.size();
			}
		}
	}
	int num=0;
	for(auto i:s){
		nu[++num]=a[i];
//		cout<<a[i]<<" ";
	}
	int ans=nu[num];
	for(int i=num;i>num-m;i--){
		ans&=nu[i];
//		cout<<nu[i]<<" ";
	}
	cout<<ans;
	return 0;
}

