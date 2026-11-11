#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
bool cnt[200005][33];
struct nod{
	int f,g,h;
}cnt2[200005];
int cmp(nod x,nod y){
	if(x.f!=y.f){
		return x.f>y.f;
	}else{
		return x.g<y.g;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		cnt2[i].h=i;
		int t=32;
		while(x){
			cnt[i][t]=x%2;
			x/=2;
			t--;
			cnt2[i].g++;
		}
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n]<<endl;
		return 0;
	}
	else if(m==n){
		int ans2=a[1];
		for(int i=1;i<=n;i++){
			ans2 = ans2 & a[i];
		}
		cout<<ans2;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<=32;j++){
				if(cnt[i][j]==1){
					cnt2[i].f=32-j+1;
					break;
				}
			}
		}	
		sort(cnt2+1,cnt2+1+n,cmp);
		int ans=a[cnt2[1].h];
		for(int i=1;i<=m;i++){
			ans = ans & a[cnt2[i].h];
		}
		cout<<ans;
	}
	
	
	return 0;
}
