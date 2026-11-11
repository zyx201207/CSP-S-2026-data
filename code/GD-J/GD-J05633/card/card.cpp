#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[5050],b[5050],num[5050],be[5050];
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		bool v[5050];
		for(int j=i;j<n;j++){
	    	b[j]=a[j];
	    	be[j]=0;
	    	v[j]=true;
	    }
	    for(int j=n-1;j>=0;j--){
	    	if(v[b[j]]==false){
	    		for(int k=be[b[j]]-1;k>=0;k--){
	    			b[k]=0;
				}
				break;
			}
			v[b[j]]=false;
			be[b[j]]=j;
		}
		for(int j=i;j<n;j++){
	    	num[b[j]]++;
	    }
	}
	for(int i=1;i<n;i++){
		cout<<num[i]<<' ';
	}
	
}
