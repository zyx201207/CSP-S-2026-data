#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int n,m,ans=0,sum=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    if(m==1){
		cout<<0;
		return 0;
		}
		if(n==m){
		for(int i=0;i<n;i++){
	        cin>>a[i];
	        if(ans==0){
			sum=a[0]&a[1];
			ans++;
			i++;
			}else{
				sum=sum&a[i];
			}
		}
		cout<<sum;
			}
    return 0;
}


