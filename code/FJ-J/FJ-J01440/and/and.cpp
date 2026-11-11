#include <bits/stdc++.h>
using namespace std;
int a[200005];
long long book[35];
long long cw[200005][35];
queue<int> q[35];
bool b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;	
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long l=1;
		int cnt=0;
		while(l<=a[i]){
			if(a[i]&l){
				book[cnt]++;
				q[cnt].push(i);
				cw[i][cnt]=1;
			}
			cnt++;
			l*=2;
		}
	}
	long long ans=0;
	int ft=0;
	bool pd=true;
	for(int i=30;i>=0;i--){
		if(book[i]>=m){
			ft=i;
			pd=false;
			break;
		}
	}
	if(pd==true){
		cout<<0;
		return 0;
	}
	
	while(ft>=0){
		memset(book,0,sizeof(book));
		ans+=(1<<ft);
		while(!q[ft].empty()){
			int u=q[ft].front();
			q[ft].pop();
			b[u]=true;
		}
		int cnt=0;
		pd=0;
		for(int j=ft-1;j>=0;j--){
			cnt=0;
			queue<int> q2;
			while(!q[j].empty()){
				int u=q[j].front();
				if(b[u]){
					cnt++;
					q2.push(u);
				}
				q[j].pop();
			}
			if(cnt>=m){
				q[j]=q2;
				pd=1;
				ft=j;
				break;
			}
		}
		if(pd==0){
			break;
		}
	}
	cout<<ans;
	
	
	return 0;
}
