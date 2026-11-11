#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,st1[N],st[N],st2[N],sum,sum1,sum2,ans;
char s[N],s1[N],s2[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>st[i]>>s[i];
		sum+=st[i];
	}sum1=sum/2;
	sum2=sum/2;
	for(int i=1,j=n;i<=n;i++,j--){
		s1[i]=s[i];
		s2[i]=s[j];
		st1[i]=min(sum1,st[i]);
		sum1-=st1[i];
		st2[i]=min(sum2,st[j]);
		sum2-=st2[i];
	}
	for(int i=0,j=0;1;){
		if(sum1>sum2 and (st2[j]!=0 or j==0)){
			sum2+=st2[++j];
			if(s2[j]!=s1[i]){
				ans+=min(sum1-sum2+st2[j],st2[j]);
			}
		}else{
			sum1+=st1[++i];
			if(s2[j]!=s1[i]){
				ans+=min(sum2-sum1+st1[i],st1[i]);
			}
		}if(st1[i+1]==0 and 0==st2[j+1] and i!=0 and j!=0){
			cout<<ans;
			return 0;
		}
	}cout<<ans;
	return 0;
}
