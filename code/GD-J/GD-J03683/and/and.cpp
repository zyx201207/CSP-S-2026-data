#include<bits/stdc++.h>
#define int long long
using namespace std;
int t[40][200005],a[200005];
bool hys[200005];
inline int read(){
	int _=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		_=_*10+ch-'0';
		ch=getchar();
	}
	return _*f;
}
inline void solve(int x,int h){
	vector<int> v;
	while(x>0){
		v.push_back(x%2);
		x/=2;
	}
	for(int i=0;i<v.size();i++){
		t[i][h]+=v[i];
		t[i][0]+=v[i];
	}
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	n=read(),m=read();
	for(int i=1;i<=n;i++) hys[i]=1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		solve(a[i],i);	
	}
	for(int i=31;i>=0;i--){
		vector<int> b;
		if(t[i][0]>=m){
			for(int j=1;j<=n;j++){
				if(hys[j]==1&&t[i][j]==0){
					hys[j]=0;
					b.push_back(j);
				}
			}
		}
		int sum=0;
		for(int j=1;j<=n;j++) if(hys[j]==1) sum++;	
		if(sum<m){
			for(int i=0;i<b.size();i++){
				hys[b[i]]=1;
			}
		}
	}
	int ans=0,sum=1;
	for(int i=1;i<=n;i++){
		if(sum==1&&hys[i]==1){
			ans=a[i];
			sum++;
		} 
		else if(sum<=m&&hys[i]==1){
			ans&=a[i];
			sum++;
		}
	}
	cout<<ans;
	return 0;
} 
