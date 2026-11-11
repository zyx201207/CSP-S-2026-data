#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],pz[100001];
int x[300005];
int y[300005];
int w(int s){
	int r=0;
	for(int i=s;i<=n;i++){
		if(x[a[i]]==0){
			pz[r+1]=a[i];
			x[a[i]]=r+1;
			r++;
		}
		else{
			for(int j=x[a[i]]+1;j<=r;j++){
				x[a[j]]=0;
				pz[j]=0;
			}
			r=x[a[i]];
		}
		for(int j=1;j<=r;j++){
			//cout<<pz[j]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=r;i++){
		y[pz[i]]++;
		//cout<<pz[i]<<" ";
		pz[i]=0;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		w(i);
	}
	cout<<endl;
	for(int i=1;i<=m;i++){
		if(y[a[i]]!=0){
			cout<<y[a[i]]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
