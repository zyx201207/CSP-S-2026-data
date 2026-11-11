#include<bits/stdc++.h>
using namespace std;
int n,m,cnt[100001],ans,now;
char num[1000001],tong[999999999+1000000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>cnt[i]>>num[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cnt[i];j++){
			tong[now]=num[i];
			now++;}}
	for(int i=1;i<=n/2;i++){
		for(int j=n;j>=n/2;j--){
			if(num[i]!=num[j]){
				ans++;
	}}}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
