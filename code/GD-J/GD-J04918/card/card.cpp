#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500007];
int t[500007];
int b[500007];
int k=1;
int find(int mj){
	for(int i=1;i<k;i++) 
		if(b[i]==mj) return i;
		return 0;
}
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++) t[i]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		t[a[i]]++;
		if(t[a[i]]>1){
			int l=find(a[i]);
			for(int i=l;i<k;i++) t[a[i]]-=1;
			k=l;
		}
		b[k++]=a[i];
		
	} 
	for(int i=1;i<k;i++) cout<<b[i]<<" ";
	return 0;
} 
