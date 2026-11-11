#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int top;
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		top=0;
		for(int j=i;j<=n;j++){
			bool f=true;
			int s;
			for(int k=1;k<=top;k++){
				if(b[k]==a[j]){
					f=false;
					s=k;
					break;
				}
			}
			if(f){
				top++;
				b[top]=a[j];
			}
			else{
				top=s;
			}
		}
		for(int j=1;j<=top;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
