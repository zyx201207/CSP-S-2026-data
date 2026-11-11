#include<bits/stdc++.h>
using namespace std;
long long  a[500005],b[300005],t[500005],j[500005];//a模拟牌,b写该排在第几位 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>t[i];
	}
	int k=1;
	int g=n;
	int f=0;
	for(int i=0;i<n*(n+1)/2;i++){
		
		if(b[t[f]]!=0){
			
			for(int l=b[t[f]]+1;l<=k;l++){
				b[a[l]]=0;
				a[l]=0;
			}k=b[t[f]];
		}
		a[k]=t[f],b[t[f]]=k;
		k++;
		if(i==g-1){
			for(int l=1;l<k;l++){
				j[a[l]]++;
			}
			g-=1;
			for(int l=1;l<=g;l++){
				t[l-1]=t[l];
			}
			g*=2;
			g+=1;
			f=0;
		}
		f++;
	}
	for(int i=1;i<=m;i++){
		cout<<j[i]<<" ";
	}
}
