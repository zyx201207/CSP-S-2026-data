#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],v[500005],d[500005];
int b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		if(n>=5000){
			for(int i=1;i<=m;i++){
		 	cout<<n-i+1<<" ";
		 }
		 return 0;
		} 
 		for(int k=1;k<=n;k++){
 			int cnt=0;
 			for(int i=k-1+1;i<=m;i++){
			 
 			if(v[a[i]]==0){
 				d[++cnt]=a[i];
 				v[a[i]]=1;
			 }
			 else{
			 	for(int j=1;j<=cnt;j++){
			 		if(d[j]==a[i]){
			 			v[a[i]]=0;
			 			int sum=cnt;
			 			for(int q=j;q<=sum;q++){
			 				v[d[q]]=0;
			 				d[q]=0;
			 				cnt--;
						 }
					 }
				 }
				 d[++cnt]=a[i];
				 v[a[i]]=1;
			 }
		
		}
		for(int q=1;q<=cnt;q++){
			 	b[d[q]]++;
		}
		 }
		 for(int i=1;i<=m;i++){
		 	cout<<b[i]<<" ";
		 }
		 return 0;
} 
