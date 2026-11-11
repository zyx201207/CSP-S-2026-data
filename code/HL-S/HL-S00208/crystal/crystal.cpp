#include<bits/stdc++.h>
using namespace std;
long long a[100050],b[100050];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,ans=0,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
    	if(a[i]>=a[i-1]){
    		b[i]=a[i]-a[i-1];
		}else{
			b[i]=a[i-1]-a[i];
		}
    }
    sort(b,b+n);
	for(int i=1;i<=n;i++){
		if(ans+b[i]<=m){
			ans+=b[i];
			cnt++;
		}
	} 
	cout<<cnt<<endl; 
    return 0;
}

