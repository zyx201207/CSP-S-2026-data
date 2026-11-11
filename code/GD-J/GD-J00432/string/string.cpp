#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n;
int a[N];
char ch[N];
long long sum;
long long qa[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		cin>>ch[i];
		sum+=a[i];
		qa[i]=qa[i-1]+(long long)a[i];
	}
	
	long long ans=0;
	long long xbi=1,xbj=sum;
	for(int i=1,j=n;xbi<xbj && i<j;) {
		if(ch[i]==ch[j]) {
			if(a[i]>a[j]) {
				xbi+=a[j];
				xbj-=a[j];
				a[i]-=a[j];
				j--;
			}
			else {
				xbi+=a[i];
				xbj-=a[i];
				a[j]-=a[i];
				i++;
				
				if(!a[j]) {
					j--;
				}
			}
		}
		else {
			if(a[i]>a[j]) {
				xbi+=a[j];
				xbj-=a[j];
				
				ans+=a[j];
				
				a[i]-=a[j];
				j--;
			}
			else {
				xbi+=a[i];
				xbj-=a[i];
				
				ans+=a[i];
				a[j]-=a[i];
				i++;
				
				if(!a[j]) {
					j--;
				}
			}
		}
	} 
	
	printf("%lld",ans);
	return 0;
}
