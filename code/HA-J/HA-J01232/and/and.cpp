#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100005];
int maxx=0;
int aand;
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int mm=1;
		aand=a[i];
		for(int j=0;j<n;j++){
			if(i==j) continue;
			if(mm==m) break;
			aand=aand & a[j];
			cout<<"A"<<aand<<endl;
			mm++;
		}
		cout<<"A"<<aand<<"M"<<maxx<<endl;
		maxx=max(maxx,aand);
	}
	cout<<maxx;
	fclose(stdin);fclose(stdout);
	return 0;
}
