#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,i=0;
	cin>>n>>m;
	int a[n+5],b[m+5]={0};
	for(;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		int j=i,l=0,q[n-i+5],p[m+3][2]={0};
		for(;j<n;j++){
			if(p[a[j]][0]==0){
				q[l]=a[j];
				l++;
				p[a[j]][0]=1;
				p[a[j]][1]=l;
			}
			else{
				for(int r=p[a[j]][1];r<l;r++){
					p[q[r]][0]=0;
					p[q[r]][1]=0;
					q[r]=0;
				}
			}
		}
		for(j=1;j<=m;j++){
			b[j]+=p[j][0];
		}
	}
	for(i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
