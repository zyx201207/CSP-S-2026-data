#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[210000];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	if(n==m){
	    ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
	}
	else if(m==1){
        for(int i=1;i<=n;i++){
            if(a[i]>ans) ans=a[i];
        }
	}
	else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int k=a[i]&a[j];
                if(k>ans) ans=k;
            }
        }
	}
	else{
        sort(a+1,a+n+1,cmp);
        ans=a[1];
        for(int i=2;i<=m;i++){
            ans=ans&a[i];
        }
	}
	cout<<ans;
	return 0;
}