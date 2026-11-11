#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int arr[N],z[10005],b[N],n,m,idx;
int search(int b[],int adx){
	bool book[adx+5]; 
	for(int k=1;k<=adx;k++){
		book[k]=false;
	}
	int book2[adx+5]={0};
	for(int k=1;k<=adx;k++){
		if(book[b[k]]==false){
			book[b[k]]=true;
			book2[b[k]]=k;
		}
		else{
			n-=k-book2[b[k]];
			book2[b[k]]=k;
			for(int l=book2[b[k]];l<=k;l++){
				b[l]=0;
			}
		}
	}
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.in","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		z[arr[i]]++;
	}
	for(int i=1;i<=n;i++){
		b[N]={0},idx=1;
		for(int j=i;j<=n;j++){
			b[idx++]=arr[j];
		}
		search(b,idx);
		for(int j=1;j<=idx;j++){
			if(b[j]==0){
				
			}
		}
	}
	return 0;
}
