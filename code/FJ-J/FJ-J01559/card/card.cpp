#include<bits/stdc++.h>
using namespace std;
int arr[200005];
int jsq[200005];
bool gh[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>arr[i];
	}
	for(int i=1;i<=n;++i){
		int k=n;
		gh[arr[i]]=true;
		for(int j=i;j<=n;){
			if(k==j){
				j++;
				k=n;
				gh[arr[j]]=true;
			}
			if(arr[j]!=arr[k])k--;
			else{
				j=k+1;
				k=n;
				gh[arr[j]]=true;
			}
		}
//		cout<<i<<" ";
		for(int j=1;j<=m;++j){		
			if(gh[j]){
//				cout<<j<<" ";
				jsq[j]++;	
			}gh[j]=false;
		}
//		cout<<"\n";
	}
	for(int i=1;i<=m;++i){
		if(i!=m){
			cout<<jsq[i]<<" ";
		}
		else{
			cout<<jsq[i];
		}
	}
}
