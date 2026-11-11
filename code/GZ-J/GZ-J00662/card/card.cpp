//GZ-J00662 都匀第十中学 郑杰康
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],ct,c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<n;j++){
			for(int k=0;k<ct;k++){
				if(b[k]==a[j]){
					ct=k;
					break;
				}
			}
			b[ct]=a[j];
			ct++;
		}
		for(int j=0;j<ct;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
