#include<bits/stdc++.h>

typedef long long LL;
typedef unsigned long long ULL;

#define mkp make_pair
#define PII pair<int,int>

using namespace std;

const int N=2e5+10;

int n;
int a[N];
char c[N];

LL ans;

int main(){
	freopen("string.in","r",stdin);
	// freopen("string6.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cin>>c[i];
	}

	for(int i=1,j=n;i<j;){
		if(a[i]<a[j]){
			if(c[i]==c[j]){
				a[j]-=a[i];
				i++;
			}
			else{
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}
		}
		else if(a[i]>a[j]){
			if(c[i]==c[j]){
				a[i]-=a[j];
				j--;
			}
			else{
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}
		}
		else{
			if(c[i]==c[j]){
				i++,j--;
			}
			else{
				ans+=a[i];
				i++,j--;
			}
		}
	}

	printf("%lld\n",ans);
	return 0;
}
