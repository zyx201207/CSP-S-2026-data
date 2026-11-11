#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll wei[200100],ans=0;//wei[i]=a[1]+a[2]+...+a[i]
int n;
int a[200100];
char s[200100];
ll l,r,cnt1,cnt2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char s_in[11];
		scanf("%d%s",&a[i],s_in+1);
		s[i]=s_in[1];
		wei[i]=wei[i-1]+a[i];
	}
	l=1,r=wei[n],cnt1=1,cnt2=n-1;//没改wei[cnt1],wei[cnt2]+1上的数 
	while(l<r){//该改l和r上的字母 
		int minn=min(wei[cnt1]-l+1,r-wei[cnt2]);
		if(minn>0){
			l+=minn,r-=minn;
			if(s[cnt1]!=s[cnt2+1]) ans+=minn;//wei[i]上的字符是s[i] 
		}
		if(minn==0){
			if(r==wei[cnt2]){
				cnt2--;
			}
			if(l==wei[cnt1]+1){
				cnt1++;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
