#include<bits/stdc++.h>
using namespace std;
int arr[200010][2];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		char o;
	cin>>arr[i][0]>>o;
	arr[i][1]=o-'a'+1;
	}
	long long up=1,down=n,ans=0;
	while(up<down){
		//cout<<up<<' '<<down<<' '<<arr[up][0]<<' '<<arr[down][0]<<endl;
		int v=min(arr[up][0],arr[down][0]);
		if(arr[up][1]!=arr[down][1])ans+=v;
		arr[up][0]-=v;
		arr[down][0]-=v;
		if(arr[up][0]==0)up++;
		if(arr[down][0]==0)down--;
		}
		cout<<ans;
return  0;
}
