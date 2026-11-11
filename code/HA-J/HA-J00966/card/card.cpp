#include<bits/stdc++.h>
using namespace std;//freopen!!!!!!!!!!!!
	int n,m,a[200005];
	int bb[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=0;k<n;k++){
		bool b[300005]={0};
		int w;
		for(int i=1+k;i<=n;i++){
//			cout<<a[i]<<" ";
			if(b[a[i]]==0){
				b[a[i]]=1;
			}
			else{
//				cout<<a[i]<<" ";
				
				for(int j=i-1;j>=1+k;j--){
					if(a[j]==a[i]){
//						cout<<a[j]<<endl;
						w=j;
						break;
					}
				}
				for(int j=w;j<i;j++){
					b[a[j]]=0;
				}
				b[a[i]]=1;
			}
		}
//		cout<<endl;
		for(int i=1;i<=m;i++){
			if(b[i]==1){
//				cout<<i<<" ";
				bb[i]++;
			}
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<bb[i]<<" ";
	}
	return 0;
}

