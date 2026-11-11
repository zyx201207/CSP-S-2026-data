#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],max=0,cnt=n+1;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
    for(int i=n-1;i>=0;i--){
    	max=0;
    	for(int j=i-1;j>=0;j--){
    		max=max+a[i]-a[j];
		}
		cnt--;
		//cout<<max<<" "<<cnt<<endl;
		if(max<=m){
			cout<<cnt;
    		break;
		}
	}
    return 0; 
}
