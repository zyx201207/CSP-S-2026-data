#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=4e5;
char ch[2];
ll ans,s1,s2,s3;
int n,a[N],c[N],x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		scanf("%s",ch);
		c[i]=ch[0]-'a',s3+=a[i];
	}int cc=0,j=n;s3/=2;
	for(int i=1;i<j;i++){
		s1+=a[i];
		while(s1>s2&&i<j){
			if(s1>=s2+a[j]){
				if(c[i]!=c[j])
					ans+=a[j];
				s2+=a[j--];
			}else{
				if(c[i]!=c[j])
					ans+=s1-s2;
				a[j]-=s1-s2,s2=s1;
			}
			
		}if(c[i]!=c[j])
			ans+=s2-s1;
		a[j]-=s2-s1,s2=s1;
	}printf("%lld",ans);
	return 0;
}

