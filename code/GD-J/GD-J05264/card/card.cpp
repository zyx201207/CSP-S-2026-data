#include<bits/stdc++.h>
using namespace std;
int a[500005],row[500005],b[300005];
bool apr[500005]={false};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		b[i]=0;
	}
	for(int j=1;j<=n;j++){
		int r=1;
		for(int i=1;i<=m;i++) apr[i]=false;
		for(int i=j;i<=n;i++){
			if(apr[a[i]]){
				while(row[r]!=a[i]){
					r--;
				}
			}
			row[r]=a[i];
			r++;
			apr[a[i]]=true;
		}
		for(int i=1;i<r;i++){
			//cout<<row[r]<<" ";
			b[row[r]]+=1;
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

