#include<bits/stdc++.h>
using namespace std;
const int MAX=8e5+5;
int n,m;
int a[MAX];
int b[MAX];
int ans[MAX];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=i;j<=n;j++){
			bool f=1;
			int kk=0;
			for(int k=1;k<=num;k++){
				if(b[k]==a[j]){
					for(int l=k+1;l<=num;l++)b[l]=0;
					f=0;
					num=k;
					break;
				}
			}
			if(f==1){
				b[num+1]=a[j];
				num++;
			}
		}
		for(int i=1;i<=num;i++)ans[b[i]]++;
		memset(b,0,sizeof(n));
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
