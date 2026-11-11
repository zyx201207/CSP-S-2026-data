#include<bits/stdc++.h>
using namespace std;
int N=5*1e5+7,M=3*1e5+7;

int main(){
	ifstream in("card.in");
	ofstream out("card.out");
	bool c[M]={};
	int ans[N]={};
	int a[M]={};
	int b[M];
	int m,n;
	in>>m>>n;
	for(int i=1;i<=m;i++){
		in>>ans[i];
	}
	for(int i=1;i<=n;i++){
		int s=0;
		for(int j=i;j<=n;j++){
			int k=ans[j];
			if(c[k]==0){
				c[k]=1;
				b[j-s]=k;
				continue;
			}
			while(b[j-s-1]!=b[j-s]){
				c[b[j-s-1]]=0;
				b[j-s-1]=b[j-s];
				b[j-s]=0;
				s++;
			}
		}
		int q=0;
		while(b[q]!=0){
			a[b[q]]++;
			c[b[q]]=0;
			q++;
		}
	}
	for(int i=1;i<=n;i++)out<<a[i]<<" ";
	return 0;
}
