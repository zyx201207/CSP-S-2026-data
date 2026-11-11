#include<bits/stdc++.h>
using namespace std;
int a[50005],c[50005],d[50005];
struct st{
	int sum,id;
}b[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	int n,m,l;
	cin>>n>>m;
	l=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;n--){
			b[j].sum=a[j];
			b[j].id=j;
			if(d[b[j].sum]!=0){
				for(int k=d[b[j].sum];k<b[j].id;k++){
					b[k].sum=0;
				}
			}
			d[b[j].sum]=b[j].id;
		}
		n=l;
		for(int j=1;j<=n;j++){
			if(b[j].sum!=0){
				c[b[j].sum]++;
				b[j].sum=0;
				b[j].id=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
	return 0;
}
