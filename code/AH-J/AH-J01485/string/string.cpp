#include "bits/stdc++.h"
using namespace std;
int n;
long long aa[200005],a[200005],l;
char cc[200005],c[200005];
int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	scanf ("%d",&n);
	for (int i=1;i<=n;i++){
		cin >> aa[i] >> cc[i];
		a[i]=aa[i]; c[i]=cc[i];
	}
	int i=1,j=n;
	long long ans1=0,ans2=0;
	for (;i<=j;){
		if (c[i]==c[j]){
			if (a[i]<a[j]){
				a[j]-=a[i]; i++;
			}
			else if (a[i]==a[j]) i++,j--;
			else if (a[i]>a[j]){
				a[i]-=a[j]; j--;
			}
		}
		else{
			if (a[i]<a[j]){
				ans1+=a[i]; a[j]-=a[i]; i++;
			}
			else if (a[i]==a[j]){
				ans1+=a[i]; i++; j--;
			}
			else if (a[i]>a[j]){
				ans1+=a[j]; a[i]-=a[j]; j--; 
			}
		}
	}
	i=1,j=n;
	for (;i<j;){
		if (cc[i]==cc[j]){
			if (aa[i]<aa[j]){
				aa[j]-=aa[i]; i++;
			}
			else if (aa[i]==aa[j]){
				i++; j--;
			}
			else if (aa[i]>aa[j]){
				aa[i]-=aa[j]; j--;
			}
		}
		else {
			if (aa[i]<aa[j]){
				ans2+=a[i]; aa[j]-=aa[i]; i++;
			}
			else if (aa[i]==aa[j]){
				ans2+=aa[i]; i++; j--;
			} 
			else if (aa[i]>aa[j]){
				ans2+=aa[j]; aa[i]-=aa[j]; j--;
			}
		}
	}
	if (ans1>ans2) printf ("%lld",ans2);
	else printf ("%lld",ans1);
	return 0;
}
