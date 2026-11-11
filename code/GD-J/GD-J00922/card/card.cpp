#include<bits/stdc++.h>
using namespace std;
int a[300010],_[300010];
int temp[300010];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int next=0,flag=0;
			for(int k=1;k<=n;k++){
				if(temp[k]==a[j]){
					memset(temp+k,0,300010-k+1);
					next=k;
					flag=1;
					break;
				}
				if(temp[k]==0){
					next=k;
					break;
				}
			}
			temp[next]=a[j];
//			cout<<next<<'='<<a[j]<<endl;
		}
		for(int j=1;j<=n;j++){
			if(temp[j]==0)break;
			_[temp[j]]++;
		}
		memset(temp,0,300010);
	}
	for(int i=1;i<=m;i++){
		cout<<_[i]<<' ';
	}
	return 0;
}
