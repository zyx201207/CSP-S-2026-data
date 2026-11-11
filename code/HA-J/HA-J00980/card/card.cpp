#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,m,a[N],b[N],ans[N];
int l,tab[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(tab,0,sizeof(tab));
		l=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]!=0&&b[a[j]]<=l&&tab[b[a[j]]]==a[j]){
				l=b[a[j]];
			}else{
				l++;
				tab[l]=a[j];
				b[a[j]]=l;
			} 
			
//			for(int k=1;k<=l;k++){
//				cout<<tab[k]<<" ";
//			}cout<<endl;
		}
		
		for(int j=1;j<=l;j++){
			ans[tab[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
