#include<bits/stdc++.h> 
using namespace std;
int in(int a[],int start,int n,int l){
	for(int i=start+1;i<l;i++){
		if(a[i]==n){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int card[n+1];
	for(int i=0;i<n;i++){
		cin>>card[i];
	}
	int ans[m+1];
	for(int i=0;i<m;i++){
		ans[i]=0;
	}
	int index=0;
	int l;
	for(int i=0;i<n;i++){
		index=i;
		while(index<n){
			l=in(card,index,card[index],n);
	  		if(l>-1){
	  			index=l;
			}
			else{
				ans[card[index]-1]++;
				index++;
			}
		}
	}

	for(int i=0;i<m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
