#include<bits/stdc++.h>
using namespace std;
int n,m,b[200005][35],c[35],cnt;
long long a[200005],ans,t,x;
bool ok;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t=a[i],cnt=0;
		while(t){
			b[i][cnt]=t%2;
			c[cnt++]+=t%2;
			t/=2;
		}
	}
	for(int i=29;i>=0;i--){
		if(ok){
			cnt=0;
			for(int j=1;j<=n;j++){
				if(b[j][x]==1&&b[j][i]==1){
					cnt++;
					if(cnt>=m){
						x=i;
						ans+=pow(2,i);
						break;
					}
				}
			}
		}
		if(!ok&&c[i]>=m){
			ok=1;
			x=i;
			ans+=pow(2,i);
		}
	}
	cout<<ans;
	return 0;
} 
