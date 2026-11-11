#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max=-1e12,ma=0,sum=m;
	for(int i=0;i<n;i++){
		if(max<a[i]){
			max=a[i];
		}
		sum+=a[i];
		if(sum/max==i+1 && i+1>ma){
			ma=i+1;
		}
	}
	cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
