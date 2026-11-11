#include<bits/stdc++.h>
using namespace std;
int n,m,p,f;
int a[500010],b[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=n;
	while(cnt){
		f++;
		memset(b,sizeof(b),1);
		for(int i=f;i<=n;i++){
			b[a[i]]++;
			if(b[a[i]]==3){
				memset(b,sizeof(b),1);
				b[a[i]]++;
				p=i;
			}
		for(int i=p;i<=n;i++){
			ans[a[i]]++;
		}
		cnt--;
		}
	}for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
