#include<bits/stdc++.h>
using namespace std;

int a[200005],n;
char b[200005];
long long cnt,ans,cnt1;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		cnt+=a[i];
	}
	cnt1=cnt;
	if(cnt%2==1)cnt=(cnt-1)/2;
	else cnt/=2;
	int bbb=0,ccc=n+1;
	for(long long i=0,j=0;i<cnt;){
		i+=a[++bbb];
		if(i>cnt){
			a[bbb]=i-cnt;
			i=cnt;
		}
		while(j<i){
			j+=a[--ccc];
			if(b[bbb]!=b[ccc])ans+=a[ccc];
		}
		if(j>i){
			a[ccc]=j-i;
			j-=a[ccc];
			if(b[bbb]!=b[ccc])ans-=a[ccc];
			ccc++;
		}
	}
	cout<<ans;
}
