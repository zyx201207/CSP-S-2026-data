#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5000;
int n,m;
int a[N],top;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    top=n;
    int ans=0;
    for(int k=30;k>=0;k--){
    	int cnt=0;
    	for(int i=1;i<=top;i++){
    		if((a[i]>>k)&1)cnt++;
		} 
		if(cnt>=m){
			ans|=1<<k;
			int topp=0;
			for(int i=1;i<=top;i++){
    			if((a[i]>>k)&1)a[++topp]=a[i];
			} 
			top=topp;
		}
	}
	cout<<ans;
	return 0;
}

