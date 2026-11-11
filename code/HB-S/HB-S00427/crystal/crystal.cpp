#include<bits/stdc++.h>
using namespace std;

int a[50005];
int ans[50005];
int num[50005];
int main(){
	freopen("crystal.cpp","r",stdin);
	freopen("crystal.cpp","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    long long m;
    int n,d;
    cin>>n>>m;
        
    for(int i=0;i<n;++i){
		cin>>a[i];
	}
	d=a[2]-a[1];
	if(d==1){ cout<<m;
	} else if(d==0) cout<<n;
              
			
		

	return 0;
}
