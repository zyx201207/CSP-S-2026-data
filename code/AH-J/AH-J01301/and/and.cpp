#include<bits/stdc++.h>
using namespace std;
long long n,m,arr[200005],x,Max;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> arr[i];
	if(m==1){
		sort(arr+1,arr+1+n);
		cout<<arr[n];
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(arr[i]!=arr[j]){
					long long tmp=arr[i];
					tmp&=arr[j];
					Max=max(Max,tmp);
				}
			} 
		}
		cout<<Max;
	}
	return 0;
}
