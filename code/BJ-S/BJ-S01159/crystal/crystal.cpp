#include<bits/stdc++.h>
using namespace std;
int a[10000005];




int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	

    int z,n,m,ans,lin;
    cin>>n>>m;
    ans=0;
    lin=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        z=a[i];
        for(int j=i;j>=0;j--){
            if(a[j]<=z&&m>a[j]){
				m=m-(z-a[j]);
                lin++;
				}
			else if(m==a[j]){
				lin++;
			}
			if(lin>ans){
				ans=lin;
				lin=0;
			}
        }
    }
    cout<<ans;
    return 0;
}
