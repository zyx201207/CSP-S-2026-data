#include<bits/stdc++.h>
using namespace std;
	int num;
	char charr;
long long len=0,ans=0;
string brr;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num;
		cin>>charr;
		len+=num;
		while(num--){
			brr+=charr;
		}
		}
	for(int i=0;i<=(len-1)/2;i++){
		if(brr[i]!=brr[(len-1)-i]){
			ans++;
		}
	}
	if(ans==0)
	cout<<0<<endl;
	else cout<<ans<<endl;
	return 0;
}
