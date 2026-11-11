#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005],b[200005],top=0,out[200005]={0};

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	for(int i=0;i<n;i++){
		top=0;
		for(int j=i;j<n;j++){
			int c=-1;
			for(int k=0;k<top;k++){
				if(b[k]==a[j]){
					c=k;
					break;
				}
			}
			if(c==-1){
				
				b[top]=a[j];
				top++;
			}else{
				top=c+1;
			}
			
		}
		
		for(int i=0;i<top;i++){
			out[b[i]]++;
		}
		
	}
	
	for(int i=1;i<=m;i++){
		cout<<out[i]<<' ';
	}

	return 0;
}
