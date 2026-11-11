#include<bits/stdc++.h>
using namespace std;
long long a[200100];
char s[200100];
long long cnt=0;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&s[i]);
	}
	int l=1,r=a[n],g1=1,g2=n;
	while(g1<g2||g1==g2&&l<r){
		if(s[g1]!=s[g2]){
			cnt++;
		}
		if(l>=a[g1]){
			l=1; g1++;
		}
		else l++;
		
		if(r<=1){
			r=a[g2-1];
			g2--;
		}
		else r--;
	}
	printf("%lld\n",cnt);
	return 0;
}


