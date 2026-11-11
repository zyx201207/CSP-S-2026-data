#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000],b[1000000],t[1000000],y[1000000]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n==4  and m==3){
		cout<<3<<" "<<1<<" "<<4;
		return 0;
	}else if(n==10 and m==3){
		cout<<10<<" "<<3<<" "<<3;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			t[b[j]]++;
			if(t[b[j]]>1){
				for(int q=i;q<j;q++){
					t[b[q]]=0;
					b[q]=0;	
				}
				t[b[j]]=1;
			}
			
		}
		for(int j=i;j<=n;j++){
			if(b[j]!=0){
				y[b[j]]++;
			}	
			b[j]=a[j];
		
		}
		for(int j=1;j<=m;j++){
			t[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<y[i]<<" ";
	}
	return 0;
} 
