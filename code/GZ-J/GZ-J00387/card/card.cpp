//GZ-00387 贵阳市南明区华麟学校 杨博麟 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],cnt[N],len,b[N],l[N],cntt[N];
bool f;
deque<int> q;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[a[i]]=i;
		cntt[a[i]]++;
		if(a[i]<a[i-1]) f=1;
	}
	int X=a[n];
	if(!f){
		for(int i=1;i<=m;i++) cout<<l[i]<<' ';
		return 0;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				for(int k=len;k>=1;k--){
					if(a[b[k]]==a[j]){
						len=k-1;
						break;
					}
				}
				b[++len]=j;
			}
			for(int j=1;j<=len;j++){
				//cout<<b[j]<<' ';
				cnt[a[b[j]]]++,b[j]=0;
			}
			len=0;
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
		return 0;
	}
	if(X==1) cout<<n<<" "<<cntt[2];
	else if(X==2) cout<<cntt[1]<<" "<<n;
	return 0;
}
