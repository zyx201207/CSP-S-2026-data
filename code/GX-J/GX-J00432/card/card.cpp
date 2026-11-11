#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,kards[300005],desk[300005],leave[300005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
		cin>>kards[i];
	}
	for(int l=0;l<n;l++){
	    for(int i=l;i<n;i++){
		    desk[i]=kards[i];
		        for(int j=0;j<i;j++){
			        if(desk[j]==desk[i]){
				        for(int k=j;k<i;k++){
					        desk[k]=0;
				        }
			        }
		        }
	    }
	    
		}
		for(int i=0;i<n;i++){
			if(desk[i])leave[desk[i]]++;
	}
	for(int i=0;i<m;i++)cout<<leave[i]<<" ";
}
