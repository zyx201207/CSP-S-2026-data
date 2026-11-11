#include<bits/stdc++.h>
using namespace std;
long long a[200005],s,b[200005],k,m1,m2,ans,l1,l2,e[200005];
char c[200005],d[200005],ss[200005];
int n,h,hh;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i],s+=a[i];
	m1=s/2,m2=(s+1)/2+1;
	for(int i=1;i<=n;i++){
		if(k+a[i]<m1) k+=a[i],b[++h]=a[i],d[h]=c[i];
		else{
			b[++h]=m1-k;
			d[h]=c[i];
			break;
		}
	}
	k=0;
	for(int i=1;i<=n;i++){
		if(k+a[i]<m2) k+=a[i];
		else{
			if(k<m2&&k+a[i]>=m2) e[++hh]=k+a[i]-m2+1,ss[hh]=c[i],k+=a[i];
			else if(k+a[i]>=m2&&k>=m2) e[++hh]=a[i],ss[hh]=c[i],k+=a[i]; 
		}
	}
	for(int i=1,j=hh;i<=h;i++){
		l1+=b[i];
		if(l1>l2&&ss[j]!=d[i]) ans+=b[i]-(l1-l2);
		else if(l1<=l2&&ss[j]!=d[i])ans+=b[i];
		while(j>=1&&l1>=l2){
			if(ss[j]!=d[i]&&l2+e[j]>=l1) ans+=l1-l2;
			else if(ss[j]!=d[i]) ans+=e[j];
			l2+=e[j],j--;
		}
	}
	cout<<ans;
}
