#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0;
	cin>>n>>m;
	for(int i = 0;i<n;++i){
		cin>>a[i];
		if(maxn<a[i])maxn=a[i];
	}
	if(m==1)cout<<maxn;
	if(m==2){
		for(int i = 0;i<n;++i){
			for(int j = i+1;j<n;++j){
				if(maxn<i|j)maxn=i|j;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

