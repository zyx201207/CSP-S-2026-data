#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005];
char c[200005],d[200005];
int n;
long long cnt,sum,l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		b[n-i+1]=a[i];
		d[n-i+1]=c[i];
	}
	sum=(sum+1)/2;
	int i=1,x=1;
	while(l<=sum){
		l+=min(a[i],b[x]);
		if(l>sum){
			if(a[i]<b[x]){
				a[i]-=(l-sum);
			}
			else if(b[x]<a[i]){
				b[x]-=(l-sum);
			}
			else{
				b[x]-=(l-sum);
			}
		}
		if(c[i]!=d[x]){
			if(a[i]>b[x]){
				cnt+=b[x];
				a[i]-=b[x];
				b[x]=0;
				x++;
				
			}
			else if (b[x]>a[i]){
				cnt+=a[i];
				b[x]-=a[i];
				a[i]=0;
				i++;
			}
			else{
				cnt+=a[i];
				b[x]=0;
				a[i]=0;
				i++,x++;
			}
		}
		else{
			if(a[i]>b[x]){
				a[i]-=b[x];
				b[x]=0;
				x++;
			}
			else if(b[x]>a[i]){
				b[x]-=a[i];
				a[i]=0;
				i++;
			}
			else {
				b[x]=0;
				a[i]=0;
				x++,i++;
			}
		}
		
	}
	cout<<cnt;
	return 0;
}
