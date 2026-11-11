#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    int n,m,a[500001];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }for(int i=1;i<=m;i++){
		sort(a+1,a+n+1,cmp);
		a[0]++;
	}int maxsum=0;
	for(int i=1;i<n;i++){
		int sum=0;
        for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				sum++;
			}
		}maxsum=max(maxsum,sum);
    }cout<<maxsum;
    return 0;
}
