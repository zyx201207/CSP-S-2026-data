#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	if(m==1){
        sort(a,a+n);
        cout<<a[n-1];
        return 0;
	}
	if(m==2){
        for(int i=0;i<n;i++){
             for(int j=i+1;j<n;j++){
                if(a[i]&a[j]>=ans)ans=a[i]&a[j];
            }
        }
        cout<<ans;
	}
	return 0;
}
