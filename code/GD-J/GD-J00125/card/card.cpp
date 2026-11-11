#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[500009];//手上卡片 
bool b[300009];//场上卡片是否存在
int c[300009];//卡片出现次数 

int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
int fl=1;
for(int i=1;i<=n;i++){
	cin>>a[i];
}

while (fl<=n){
	//cout<<endl<<fl<<'~';
	for(int i=fl;i<=n;i++){
		///cout<<a[i];
		if(b[a[i]]==1){
		for(int j=1;j<=m;j++){
			b[j]=0;	
		}}
		b[a[i]]=1;
	}
	//////////////////////////
//	for(int i=1;i<=m;i++){
	//	cout<<b[i]<<' ';}
		/////////////////////////////////////
	for(int i=1;i<=m;i++){
		if(b[i]==1)
		c[i]++;			
		}
	fl++;
		for(int j=1;j<=m;j++){
			b[j]=0;	
		}
}
for(int i=1;i<=m;i++){
		cout<<c[i]<<' ';}		
return 0;
}
