#include<bits/stdc++.h>
using namespace std;
int n,a[5005],m,f,x[3005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1])f=-1;
	}
	if(f==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			x[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			cnt+=x[i];
			cout<<cnt<<" ";
		}
	}else{
		for(int i=1;i<=m;i++)cout<<i<<" ";
	}
    return 0;
}
