#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int a[N],num[N];
int pr[N],ne[N];
bool here[N];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int t=1;t<=n;t++){
		int now=a[t];
		for(int i=t;i<=n;i++){
			if(here[a[i]]){
				for(int j=a[i];ne[j]!=0;j=ne[j]){
					here[j]=0;
					ne[pr[j]]=0;
					pr[j]=0;
				}
				here[a[i]]=1;
				now=a[i];
			}
			else{
				here[a[i]]=1;
				if(i!=t){
					ne[now]=a[i];
					pr[a[i]]=now;
					now=a[i];
				}
					
			}
		}
		for(int i=1;i<=m;i++){
			if(here[i])num[i]++;
//			cout<<here[i]<<" ";
		}
//		cout<<endl;
		fill(here,here+m+1,0);
//		for(int i=1;i<=m;i++){
//			cout<<here[i]<<" ";
//		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}

