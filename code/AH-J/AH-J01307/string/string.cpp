#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005],y,sum,js,k,b[400005],l1,l2,s1,s2,ans,zs;
char c[200005],c2[400005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	y=sum;
	if(sum&1) sum=sum/2+1;
	else sum=sum/2;
	for(int i=1;i<=n;i++){
		js+=a[i];
		if(js>=sum){
			js-=sum;
			k=i;
			break;
		}
	}
	for(int i=1;i<=k;i++){
		b[i]=a[i];
		c2[i]=c[i];
	}
	b[k]=(b[k]-js)*2;
	if(y&1){
		b[k]--;
	}
	for(int i=k+1;i<2*k;i++){
		b[i]=b[2*k-i];
		c2[i]=c2[2*k-i];
	}
	while(l1<=n&&l2<=2*k-1){
		if(s1==0&&s2==0){
			l1++,l2++;
			s1+=a[l1],s2+=b[l2];
			if(s1>s2){
				if(c[l1]!=c2[l2]){
					ans+=s2;
				}
				s1-=s2;
				s2=0;
			}
			else{
				if(c[l1]!=c2[l2]){
					ans+=s1;
				}
				s2-=s1;
				s1=0;
			}
		}
		if(s1==0){
			l1++;
			s1+=a[l1];
			if(s1>s2){
				if(c[l1]!=c2[l2]){
					ans+=s2;
				}
				s1-=s2,s2=0;
			}
			else{
				if(c[l1]!=c2[l2]){
					ans+=s1;
				}
				s2-=s1,s1=0;
			}
		}
		else{
			l2++;
			s2+=b[l2];
			if(s1>s2){
				if(c[l1]!=c2[l2]){
					ans+=s2;
				}
				s1-=s2,s2=0;
			}
			else{
				if(c[l1]!=c2[l2]){
					ans+=s1;
				}
				s2-=s1,s1=0;
			}
		}
	}
	cout<<ans; 
	return 0;
}

