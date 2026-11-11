#include <bits/stdc++.h>
using namespace std;
#define filename "crystal"

const int AMAX=5005;
int a[AMAX];

int main(){
	freopen(filename".in","r",stdin);
	freopen(filename".out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	int cnt=2;
	while(cnt<=n){
		int b=0;
		for(int i=0;i<cnt;i++){
			b+=a[cnt]-a[i];
		}
		if(b>m){
			break;
		}else{
			cnt++;
		}
	}
	if(cnt>n)cnt=n; 
	printf("%d",cnt);
	return 0;
}
