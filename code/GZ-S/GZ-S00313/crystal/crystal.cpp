//GZ-S00313 遵义市新蒲新区滨湖中学 胡泽雨 
#include <bits/stdc++.h>
using namespace std;

const long long N=1e6*3;
long long arr[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,ans=0,g,h;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>arr[i];
	sort(arr,arr+n);
	if(m<1e18&&m>1e9){
		if(arr[n-1]-arr[1]==arr[n]-arr[2]&&arr[n-2]-arr[0]==arr[n-1]-arr[1]){
			g=arr[2]-arr[1];
			ans=1;
			while(m>g&&ans<=n){
				h=(ans-1)*g+arr[ans];
				ans++;
			}cout<<ans;
		}return 0;
	}
	for(int i=1;i<=n;i++){
	m=m-(arr[i+1]-arr[i])*(i+1);		
	arr[i]=arr[i+1];
	if(m<=0){
		ans=i+2;
		if(arr[i+2]==arr[i]){
			while(arr[ans]==arr[i]){
				ans++;
			}
			}break;
		}
	}if(ans==0)cout<<n;
	else cout<<ans-1;
	fclose(stdin);
	fclose(stdout);
}

