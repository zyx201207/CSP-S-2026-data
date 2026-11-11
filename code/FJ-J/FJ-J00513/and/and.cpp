#include<bits/stdc++.h>
using namespace std;
int n,x,a[40],k,m,mk,b[200001],q,l=1,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		k=0;
		b[i]=x;
		while(x){
			a[++k]+=x%2;
			x>>=1;
		}
		mk=max(mk,k);
    }
    sort(b+1,b+1+n);
    q=pow(2,mk-1);
    for(int i=mk;i>=1;i--){
    	if(a[i]>=m){
    		ans+=q;
    		while(b[l]<=ans){
    			k=0;
    			x=b[l];
    			while(x){
    				a[++k]-=x%2;
			        x>>=1;
				}
    			l++;
			}
		}
		q/=2;
	}
	cout<<ans;
	return 0;
}
