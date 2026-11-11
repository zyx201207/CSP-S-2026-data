#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int b[300005];
int ans[300005];
bool book[500005];
bool p=0;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]>a[i-1]) p=1;
	}
	if(!p){
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		for(int i=0;i<n;i++){
			if(b[a[i]]==1) ans[a[i]]=i+1;
		}
		b[a[n]]=n;
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(book,0,sizeof(book));
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0){
				for(int k=b[a[j]]+1;k<j;k++){
					if(book[k]) continue;
					book[k]=1;
					b[a[k]]=0;
//					if(a[j]==1) cout<<"chaxun "<<k<<" "<<b[a[j]]<<endl;
				}
				book[j]=1;
//				if(i==2) cout<<b[2]<<" ";
			}
			else{
				b[a[j]]=j;
//				if(a[j]==1) cout<<"biaoji "<<a[j]<<" "<<j<<endl;
			}
		}
		bool q[300005];
		memset(q,0,sizeof(q));
		for(int j=i;j<=n;j++){
//			cout<<book[j]<<" ";
			if(!book[j]&&!q[a[j]]){
				ans[a[j]]++;
				q[a[j]]=1;
			}
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
//rp+=inf
