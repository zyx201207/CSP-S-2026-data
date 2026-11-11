#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m,num[200001],ans[40000001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	int z=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++,z++){
			ans[z]=num[i]&num[j];
		}
	}
	int l=1;
	if(m>2){
		for(int i=1;i<=m-2;i++){
			for(int j=1;j<=n;j++,l++){
				ans[l]=ans[l]&num[j];
			}
		}
	}
	unique(ans+1,ans+z+1);
	sort(ans+1,ans+l+1,cmp);
	cout<<ans[1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
