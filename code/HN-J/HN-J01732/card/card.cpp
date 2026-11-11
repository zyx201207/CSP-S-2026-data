#include<bits/stdc++.h>

using namespace std;

int a[500010],ans[300010],n,m,s[300010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
		if(ans[x]!=0)s[i]=ans[x];
		ans[x]=i;
//		cout<<s[3]<<" ";
	}
//	cout<<endl;
	for(int i=1;i<=m;i++)ans[i]=0;
	for(int i=n;i>0;i--){
		int w=n;
		while(w>=i){
			if(s[w]!=0&&s[w]>=i){
				w=s[w]+1;
			}
			else {
				ans[a[w]]++;
			}
			w--;
		}
	} 
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

