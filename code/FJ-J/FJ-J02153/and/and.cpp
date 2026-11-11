#include<bits/stdc++.h>
using namespace std;
int a[200005];
long long duibi=4294967295;
long long Ans1=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,Ans1=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Ans1=max(Ans1,a[i]);
		duibi=(duibi&a[i]);
	}
	if(m==1) cout<<Ans1;
	if(m==n) cout<<duibi;
	for(int i=1;i<=m;i++){
		int fb=0,num=0;
		for(int j=1;j<=n;j++){
		fb=duibi;
		num=0;	
		fb=((-fb&a[j])+1);
		num=max(num,fb);
		}
		duibi=num;	
	}
	cout<<duibi-1;
	return 0;
} 
