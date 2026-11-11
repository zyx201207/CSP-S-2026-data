#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int b[N],cnt,a[N],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(t--){
		int top=1,tail=1;
		b[1]=a[1];
		for(int i=2;i<=n;i++){
			for(int j=top;j<=tail;j++){
				if(b[j]==a[i]){
					tail=j;
					b[tail]=a[i];
					break; 
				}
			}
			for(int j=top;j<=tail;j++){
				c[b[j]]++;
			}
		}
//		memset(b,0,sizeof b);
//		top=1
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	return 0;
}

