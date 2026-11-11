#include<bits/stdc++.h>
using namespace std;
bool b[300010];
int c[300010],d[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],t=n;
	for (int i=0;i<n;i++) cin>>a[i];
	while(t--){
		for (int i=n-t-1;i<n;i++){
			if (b[a[i]-1]==0){
				b[a[i]-1]=1;
				d[a[i]-1]=i;
			}
			else{
				for (int j=0;j<m;j++){
					if (b[j]==1 && d[a[i]-1]<=d[j]){
						b[j]=0;
						d[j]=0;
					}
				}
				b[a[i]-1]=1;
				d[a[i]-1]=i;
			}
		}
		for (int i=0;i<m;i++){
			if(b[i]==1) c[i]++;
		}
		for (int i=0;i<m;i++){
			b[i]=0;
			d[i]=0;
		}
	}
	for (int i=0;i<m;i++) cout<<c[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
