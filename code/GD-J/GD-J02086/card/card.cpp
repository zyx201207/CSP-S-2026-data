#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],t[200005],b[200005]; 
int num;
int mov(int x,int y){
	b[x]=b[y+1];
	for(int i=x+1;i<x+y;i++){
		b[i]=0;
	}// 1 2 3 4 5
	num-=(y-x+1);
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	/*
	1 2 1 3
	1 3
	2 1 3
	1 3 2 1 3
	1 3
	1 3
	1 3 1 3
	3
	*/
	for(int w=0;w<n;w++){
		num=0;
		for(int i=w;i<n;i++){
			b[num]=a[i];
			for(int j=0;j<num;j++){
				if(b[j]==b[num]){
					mov(j,num-1); 
					
				} 
			}
			num++;
		}
		for(int i=0;i<num;i++){
//			cout<<b[i]<<" ";
			t[b[i]]++;
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
