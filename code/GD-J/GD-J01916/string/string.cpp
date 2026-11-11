#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],s1,s2,ans,ma;
char c[N],c1,c2;
int len;
string st;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(a[i]>ma)ma=a[i];
	}
	if((n<=2000&&ma<=50)||(n<=N&&ma==1)){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=a[i];j++)
				st=st+c[i];
		len=st.size();
		for(int i=0,j=len-1;i<j;i++,j--){
			if(st[i]!=st[j])ans++;
		}
		cout<<ans;
		return 0;
	}
	s1=a[1],s2=a[n];
	for(int i=1,j=n;i<=j;){
		c1=c[i],c2=c[j];
		if(c1!=c2){
			if(s1<s2)ans+=s1,s2-=s1,i++,s1=a[i];
			else ans+=s2,s1-=s2,j--,s2=a[j];
		}
		else{
			if(s1==s2)i++,j--,s1=a[i],s2=a[j];
			else if(s1<s2)s2-=s1,i++,s1=a[i];
			else s1-=s2,j--,s2=a[j];
		}
	}
	cout<<ans;
	return 0;
}
