#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
int n,m;
int a[MAXN];
bool out[MAXN];
bool s[MAXN][32];
int sum[32];
int maxx;
int w;
void put(int x,int num){
	int cnt=0;
	while(x!=0){
		cnt++;
		s[num][cnt]=x%2;
		if(s[num][cnt]) sum[cnt]++;
		x/=2;
	}
	maxx=max(maxx,cnt);
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		put(a[i],i);
	} 
	int p=maxx;
	while(sum[p]<m&&p>0){
		p--; 
	}
	if(p==0){
		cout<<0;
		return 0;
	}
	w=n;
	for(int i=1;i<=n;i++){
		if(!s[i][p]){
			w--;
			out[i]=1;
		}
	}
	p--;
	while(p>0){
		for(int i=1;i<=n;i++){
			if(out[i]) continue;
			if(w>m&&s[i][p]==0){
				w--;
				out[i]=1;
			} 
		}		
		p--;
	}
	int ans=0;
	bool fi=1;
	for(int i=1;i<=n;i++){
		if(!out[i]){
			if(fi){
				ans=a[i];
				fi=0;
			}
			else{
				ans=ans&a[i];
			}
		}
	}
	cout<<ans;
	return 0;
}
