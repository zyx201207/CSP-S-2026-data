#include <bits/stdc++.h>
using namespace std;
const int N=1e5*5+5;
int n,m;
int a[N]={0},b[N]={0},t[N]={0};
void fun(int c){
	for(int i=c;i<N;i++){
		if(b[i]==0){
			break;
		}
		b[i]=0;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cout.tie(0); cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		fun(0);
		for(int j=i;j<n;j++){
			int d,e; bool f=0,f1=0;
			for(int k=0;k<i+1;k++){
				if(b[k]==a[j]){
					d=k; f=1; 
				}
				if(b[k]==0&&f1==0){
					e=k;
				}
			}
			if(f){
				fun(d+2);
			}else{
				b[e]=a[j];
			}
		}
		for(int i=0;i<n;i++){
			t[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
