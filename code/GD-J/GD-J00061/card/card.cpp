#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500005];
int b[300005];
int c[500005];
int num[500005];
int ans[300005];
bool pan[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]){
			c[i]=b[a[i]];
		}else{
			b[a[i]]=i;
			c[i]=i;
		}
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int sum=1;
		memset(pan,0,sizeof(pan));
		for(int j=i;j<=n;j++){
			num[sum]=a[j];
			sum++;
			if(i<=c[j] && pan[a[j]]==true){
				sum=c[j];
			}
			pan[a[j]]=1;
		}
		for(int j=1;j<sum;j++){
			ans[num[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

