#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,t;
int a[N],js[N],b[N],mm[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(n--){
		memset(b,0,sizeof(b));
		memset(mm,0,sizeof(mm));
		for(int i=1+t;i<=n;i++){
			mm[a[i]]++;
			if(mm[a[i]]>1){
				for(int j=1;j<=i-1;j++){
					if(b[j]==a[i]){
						b[j]=0;
					}
				}
				mm[a[i]]=0;
			}
			b[i-t]=a[i];
		}	
		for(int i=1+t;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i]==j){
					js[j]++;
				}
			}
		}
		t++;
	}
	for(int i=1;i<=m;i++){
		cout<<js[i]<<" ";
	}
	return 0;
}
