#include<bits/stdc++.h>
using namespace std;
int a[50050],t[30030],b[30030],b1[30030];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
		int idx=1,idx2;
	for(int i=1;i<=n;i++){
		idx=1;
        for(int w=1;w<=m;w++){
            t[w]=0;
            b[w]=0;
        }
		for(int j=i;j<=n;j++){
				if(b[a[j]]==0){
					t[idx]=a[j];
					b[a[j]]++;
					idx++;
					}
				else{
					idx2=1;
        for(int w=1;w<=m;w++){
            b[w]=0;
        }
					while(t[idx2]!=a[j]){
						b[t[idx2]]++;
							idx2++;
						}
						idx=idx2;
						b[a[j]]++;
						t[idx]=a[j];
						idx++;

			}
		}
		for(int k=1;k<=m;k++){
	b1[k]+=b[k];
			}
	}
	for(int i=1;i<=m;i++){
		cout<<b1[i]<<" ";
		}
}
