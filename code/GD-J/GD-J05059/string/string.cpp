#include<bits/stdc++.h>
using namespace std;
const int MAXX=200005;
int n;
long long s,a[MAXX],b[MAXX],sum,k,cnt1,cnt2;
char c[MAXX],d[MAXX];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		k+=a[i];
		if(k>sum/2){
			if(sum%2==1){
				a[i]--;
				sum--;
				k--;
			}
			b[++cnt1]=k-sum/2;
			d[cnt1]=c[i];
			for(int j=i+1;j<=n;j++){
				b[++cnt1]=a[j];
				d[cnt1]=c[j];
			}
			a[i]-=b[1];
			cnt2=i;
			break;
		}
	}
	int c1=cnt2,c2=1;
	while(c1>0||c2<=cnt1+1){
		long long mi=min(a[c1],b[c2]);
		if(c[c1]!=d[c2]){
			s+=mi;
		}
		a[c1]-=mi;
		b[c2]-=mi;
		if(a[c1]<=0){
			c1--;
		}
		if(b[c2]<=0){
			c2++;
		}
	}
	cout<<s;
	return 0;
}
