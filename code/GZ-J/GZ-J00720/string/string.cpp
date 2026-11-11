//GZ-J00720 王煜航
#include<bits/stdc++.h>
using namespace std;
long long ans,a[200001],n;
char s[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}int now1=1,now2=n;
	while(now1<now2){
		if(s[now1]==s[now2]){
			if(a[now1]>a[now2]){
				a[now1]-=a[now2];
				now2--;
			}else if(a[now1]==a[now2]){
				now2--;
				now1++;
			}else{
				a[now2]-=a[now1];
				now1++;
			}
		}else{
			if(a[now1]>a[now2]){
				ans+=a[now1]-a[now2];
				a[now1]-=a[now2];
				now2--;
			}else if(a[now1]==a[now2]){
				now1++;
				now2--;
				ans+=a[now1];
			}else{
				ans+=a[now2]-a[now1];
				a[now2]-=a[now1];
				now1++;
			}
		}
	}cout<<ans;
	return 0;
}
