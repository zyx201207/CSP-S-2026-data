#include<bits/stdc++.h> 

using namespace std;
int main(){
	
int n,m;
cin>>n>>m;
int b[100001];
int nm[10111]={};
int a[100001];
for(int i=1;i<=n;i++){
	cin>>a[i];
	
}
int as=0;
int v=1;
int c;
while(m--){
	
	for(int i=as;i<=n;i++){
		b[i]=a[i];
		c=b[i];
			for(int j=1;j<=i;j++){
				if(b[j]==c){
					for(int k=j+1;k<=i;k++){
						b[k]=-1;
					}
				}
			}
			
		}
	
	as++;
	for(int l1=n;l1<=n;l1++){
		for(int l=1;l<=n;l++){
		if(v=b[l]){
			nm[v]++;
		}
	}
	v++;
	}
	
}
for(int i=1;i<=n;i++){
	cout<<nm[i]<<" ";
}
	return 0;
}
//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
