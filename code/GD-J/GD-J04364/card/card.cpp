#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int sta[N],insta[N],top=0;
int ans[N];
signed main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout); 
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(insta[a[j]]!=0){
				while(1){
					int x=sta[top--];
					insta[x]--;
					if(x==a[j]) break;
				}
			}else{
				sta[++top]=a[j];
				insta[a[j]]++;
			}
		}
		for(int j=i;j<=n;j++){
			if(insta[a[j]]!=0){
				ans[a[j]]++;
			}
		}
		top=0;
		for(int j=1;j<=n;j++){
			insta[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
