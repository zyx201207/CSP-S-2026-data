#include<bits/stdc++.h>
using namespace std;
int a[2100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	if(m==n){
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
	}
	else if(m==1)cout<<a[1];
	else if(m==2){
		int maxx=a[1]&a[2];
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(a[i]&a[j],maxx);
			}
		}
		cout<<maxx<<endl;
	}
    return 0;
}
