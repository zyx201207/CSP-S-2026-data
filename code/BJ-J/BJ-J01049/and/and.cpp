#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;
int a[200050];
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	if(n==m){
	    sum=a[1];
        for(int i=1;i<=n;i++){
            sum&=a[i];
        }
        cout<<sum;
	}else if(m==1){
	    cout<<0;
	}else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                sum=max(sum,a[i]&a[j]);
            }
        }
        cout<<sum;
	}else if(m==n){
        for(int i=1;i<=n;i++){
            sum&=a[i];
        }
        cout<<sum;
	}
	return 0;
}
