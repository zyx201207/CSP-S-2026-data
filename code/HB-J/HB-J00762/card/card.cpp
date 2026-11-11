#include<bits/stdc++.h>
using namespace std;
const int man1=5e5+10;
const int man2=3e5+10;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[man1],b[man1];
	int na[man2]={},xdch[man1]={};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		na[a[i]]++;
		b[n-i]=a[i];
	}
	int qc=0;
	bool f1[man2]={};//zhi1 qian2 shi4 fou3 chu1 xian4 guo4
	//zhi1 hou4 yong4 b
	for(int i=0;i<n;i++){
		xdch[i]=n-i-qc;
		qc=qc+na[b[i]]-1;
		if(f1[b[i]]==1)qc-=na[b[i]];
		na[b[i]]-=1;
		f1[b[i]]=1;
	}
	for(int i=0;i<n;i++){
		na[b[i]]=max(na[b[i]],xdch[i]);
	}
	for(int i=1;i<=m;i++){
		cout<<na[i]<<" ";
	}
	return 0;
}
