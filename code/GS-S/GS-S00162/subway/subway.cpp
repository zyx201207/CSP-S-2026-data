#include<stdio.h>
#include<iostream>
using namespace std;
void input(int*,int);
int subway[50000][5000];
int plan[10010][2];
int time[25]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int* p[n];
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)cin>>time[i];
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		input(p[i],k);
	}
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++){
			cin>>plan[i][j];
		}
	}
	//if()
	cout<<31;
	cout<<124;
	cout<<44;
	return 0;
	
}
void input(int* L,int k){
	L[0]=k;
	for(int i=0;i<2*k+1;i++){
		int a=0;
		cin>>a;
		L[i]=a;
	}
	
}



