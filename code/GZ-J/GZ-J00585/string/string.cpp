//GZ-J00585 李博煜 华东师范大学附属贵阳学校 
#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans=0;
long long num[200005];
char c[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>num[i]>>c[i];
	}
	long long cnt1=1,cntn=n;
	while(1){
		if(cnt1>cntn){
			cout<<ans;
			return 0;
		}
		if(num[cnt1]==num[cntn]&&c[cnt1]==c[cntn]){
			cnt1++;
			cntn--;
		}
		else if(num[cnt1]==num[cntn]&&c[cnt1]!=c[cntn]){
			ans+=num[cnt1];
			cnt1++;
			cntn--;
		}
		else if(num[cnt1]<num[cntn]&&c[cnt1]==c[cntn]){
			num[cntn]-=num[cnt1];
			cnt1++;
		}
		else if(num[cnt1]<num[cntn]&&c[cnt1]==c[cntn]){
			num[cnt1]-=num[cntn];
			cntn--;
		}
		else if(num[cnt1]<num[cntn]&&c[cnt1]!=c[cntn]){
			ans+=num[cnt1];
			num[cntn]-=num[cnt1];
			cnt1++;
		}
		else if(num[cnt1]>num[cntn]&&c[cnt1]!=c[cntn]){
			ans+=num[cntn];
			num[cnt1]-=num[cntn];
			cntn--;
		}
	}
	return 0;
}
