#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool nu[200005];

bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,man=0,ans=0,cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=200004;i++){
		nu[i]=1;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		int o=a[i];
		int y=1;
		while(o){
			int x = o%2;
			o/=2;
			if(x==0){
				nu[y]=0;
			}
			y++;
			
		}
		y-=1;
		if(y<man){
			for(int i=y+1;i<=man;i++){
				nu[i]=0;
			}
		}
		man = max(man,y);
	}
	cout<<endl;
	for(int i=1;i<=man;i++){
		if(i!=1){
			cnt*=2;
		}
		ans +=nu[i]*cnt;
	}
	cout<<ans;
	return 0;
} 



