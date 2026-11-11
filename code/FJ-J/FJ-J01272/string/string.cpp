#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+50;
int a[N],sum;char ch[N],ch1[N],ch2[N];int n;
int s1[N],s2[N],ans,num1,num2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>ch[i],sum+=a[i];int az=sum/2;sum=0;
	for(int i=1;i<=n;i++){
		if(sum<az){++num1;s1[num1]=s1[num1-1]+min(az-sum,a[i]);ch1[num1]=ch[i];}else break;
		sum+=a[i];
	}sum=0;
	for(int i=n;i>=1;i--){
		if(sum<az){++num2;s2[num2]=s2[num2-1]+min(az-sum,a[i]);ch2[num2]=ch[i];}else break;
		sum+=a[i];
	}int r1=0,r2=0;
	while(r1<num1||r2<num2){
		if(r1!=num1&&(r2==num2||s1[r1+1]<=s2[r2+1])){++r1;if(ch1[r1]!=ch2[r2+1])ans+=max(s1[r1]-max(s2[r2],s1[r1-1]),0ll);}
		else{++r2;if(ch1[r1+1]!=ch2[r2])ans+=max(s2[r2]-max(s1[r1],s2[r2-1]),0ll);}
	}cout<<ans<<'\n';return 0;
}
