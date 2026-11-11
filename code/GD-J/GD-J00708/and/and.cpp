#include<bits/stdc++.h>
using namespace std;
const int MAXN=10000005;
int a[MAXN],n,m,ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    long long max1[m];
    for(int i=0;i<n;i++){
    	cin>>a[i];
    	if(i>m-1){
    		for(int j=0;j<m;j++){
    			if(a[i]>max1[j]){
    				max1[j]=a[i];
    				break;
				}
			}
		}else{
			max1[i]=a[i];
		}
	}
	for(int i=0;i<m;i++){
		ans=min(max1[i-1],max1[i]);
	}
	cout<<ans;
	return 0;
}
