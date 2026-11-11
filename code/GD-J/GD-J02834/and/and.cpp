#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000001],ans=0,b[1000001],bb=1;
int h(int lin,int kai,int mm){
	if(mm==0){
		if(lin>ans){
			ans=lin;
		}
		return 0;
	}
	for(int i=kai;i<=n;i++){
		h(lin&a[i],i+1,mm-1);
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		h(a[i],i+1,m-1);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
