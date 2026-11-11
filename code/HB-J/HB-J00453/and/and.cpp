#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200026],cnt=INT_MIN,ar[200026],arr[200026];
void dfs(int k){
    if(k==m){
        long long t=ar[0]&ar[1];
        for(int i=2;i<m;i++){
            t=ar[i]&t;
        }
        cnt=max(cnt,t);
        return;
    }
    for(int i=k;i<n;i++){
		bool b=true;
		for(int j=0;j<k;j++){
			if(arr[j]==i) b=false;
		}
		if(b==true){
			arr[k]=i;
			ar[k]=a[i];
			dfs(k+1);
		}
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    dfs(0);
    cout<<cnt;
    return 0;
}
//while(1) rp++;
//I AK IOI!!!
