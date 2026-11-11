#include<bits/stdc++.h>
#include<vector>
using namespace std;
int n,m,a[6],ans[3],b[6];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++0){
		for(int j=i;j<=n;j++){
			for(int k=n;k>=j;k++){
				if(b[k]==b[j]){
					for(int y=1;y<=k;y++){
						b[y]=0;
					}
				}
			if(b[1]=1||b[2]=1||b[3]=1||b[4]=1||b[5]=1) {
				ans[1]+=1;
			}
			else if(b[1]=2||b[2]=2||b[3]=2||b[4]=2||b[5]=2){
				ans[2]+=1
			}
			}
			for(int j=1;j<=n;j++){
				b[j]=a[j];
			}
		}
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
