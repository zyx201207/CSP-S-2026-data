#include<bits/stdc++.h>
using namespace std;
int n,m,arr[500005],hl=0,ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

    cin>>n>>m;
    cout<<' ';
    for(int i=0;i<n;i++){
        cin>>arr[i];
   //     cout<<arr[i]<<' ';
    }
  //  cout<<'\n';
    sort(arr,arr+n);
  
    for(int i=0;i<n;i++){
		  int kl=0,pl=0;
	//	if(arr[i]>=0)cout<<' ';
	//	cout<<arr[i]<<' ';
		for(int j=0;j<n;j++){
			
				int t=arr[j]-arr[i];
				

		//		cout<<abs(t)<<' ';
				if(kl+abs(t)<=m){
					kl+=abs(t);
					pl++;
				}
		}
		hl=max(kl,hl);
		ans=max(pl,ans);
	//	cout<<' '<<kl<<' '<<pl<<'\n';
	}
	cout<<ans;
}
