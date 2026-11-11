#include<bits/stdc++.h>
using namespace std;
int main(){
	const int N=5e5+10;
	int m,n,a[N],b[N],k,s=0,p=1,mxxx=-1,x=0,z=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		k=a[i];
		x=0;
		for(int j=1;j<=n;j++){
			a[j]-=k;
		}
		sort(a,a+n+1);
		for(int y=1;y<=n;y++){
			if(a[k]<0){
				a[k]=0-a[k];
			}
			if(a[k]==0){
				x++;
			}
		}
		while(s<=m){
			s+=a[p];
			p++;
			z++;
			if(a[p]==0){
				break;
			}
		}
		if(s>m){
			z--;
		}
		//z+=x;
		mxxx=max(mxxx,z);
	}
	cout<<mxxx;
	return 0;
}
