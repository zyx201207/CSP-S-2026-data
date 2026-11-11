#include<iostream>
using namespace std;
int n,m,a[50005],b[50005],c[50005],d[50005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=1;
		for(int j=i;j<=n;j++){
			c[j]=0;
			int x=a[j];
			b[cnt]=x;
			for(int q=1;q<=n;q++){
				if(cnt==q)continue;
				if(x==b[q]){
					for(int k=q;k<j;k++){
						b[k]=0;
					}
				}
				for(int q=1;q<=n;q++){
				if(cnt==q)continue;
				if(x==b[q]){
					for(int k=q;k<j;k++){
						b[k]=0;
					}
				}
			}
			}

			cnt++;
		}
		for(int z=1;z<=n;z++){
			if(b[z]==0)continue;
			cout<<b[z];
			int y=b[z];
			c[y]++;
		}

		for(int z=1;z<=m;z++){
			if(c[z]>0){
				d[z]++;
			}
		}

		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
