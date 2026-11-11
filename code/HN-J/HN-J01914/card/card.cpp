#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e6; 
map<int,int> mp;
int n,m,a[N],b[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=0;
	//	int b[N]={};
	for(int j=1;j<=n;j++){
		b[j]=0;
	}
		for(int j=i;j<=n;j++){
			int gum=0;
			l++;
			for(int k=1;k<=l;k++){
				if(gum==1){
					b[k]=0;
				}
				if(a[j]==b[k]){
					gum=1;
					l=k;
				}				
				//cout<<b[k]<<" ";
			}
			if(gum==0){
				b[l]=a[j];
			}	
			//cout<<l<<" ";
		}
		//cout<<endl;
		for(int j=1;j<=l;j++){
			mp[b[j]]++;
		//	cout<<b[j]<<" ";
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
	//	cout<<a[i]<<" ";
		if(mp[i]!=0){
			cout<<mp[i]<<" ";
		}
	}
	return 0;
}
