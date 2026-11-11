#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N]={0};
int n,m;
const int M=3e5+5;
int maa[M]={0};
int main(){ 
		freopen("card.in","r",stdin);
		freopen("card.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	for(int i=1;i<=n;i++){
		int ex[N]={0};
		int cpo[M]={0};
		int pos1=1;
		for(int j=i-1;j<=n;j++){
			ex[pos1]=a[j];
			if(cpo[ex[pos1]]==0)cpo[ex[pos1]]=pos1;
			else {
				while(pos1>cpo[ex[pos1]]){
					cpo[pos1]=0;
					pos1--;
				}
				cpo[ex[pos1]]=pos1;
			}
			pos1++;
		}
		for(int j=1;j<pos1;j++)maa[ex[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<maa[i]<<" ";
	}
	return 0;
}
