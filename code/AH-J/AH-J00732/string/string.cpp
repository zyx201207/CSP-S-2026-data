#include<bits/stdc++.h>
using namespace std;
long long n,cnt,ans;
struct astr{
	long long siz;
	char abo;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cnt++;
		cin>>a[cnt].siz>>a[cnt].abo;
		if(a[cnt].abo==a[cnt-1].abo){
			a[cnt-1].siz+=a[cnt].siz;
			cnt--;
		}
	}
	if(cnt==1){
		cout<<0;
		return 0;
	}
	int l=1,r=cnt;
	while(l<=r){
		if(a[l].siz==a[r].siz){
			if(a[l].abo!=a[r].abo){
				ans+=a[l].siz;
			}
			l++,r--;
		}
		else{
			int mi=min(a[l].siz,a[r].siz);
			if(mi==a[r].siz){
				if(a[l].abo!=a[r].abo){
					ans+=mi;
				}
				r--;
				a[l].siz-=mi;
			}
			else{
				if(a[l].abo!=a[r].abo){
					ans+=mi;
				}
				l++;
				a[r].siz-=mi;
			}
		}
	}
	cout<<ans;
	return 0;
}
