#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=0;
long long a[200005]={};
long long b[200005]={};
char c[200005]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		a[i]+=a[i-1];
		b[n+1-i]+=b[n+2-i];
	}
	
//	for(int i=1;i<=n;i++){
//		printf("%lld ",b[i]);
//	}

	int l=1,r=n;
	while(a[l]<=(a[n]+1)/2 && b[r]<=(a[n]+1)/2){
//		cout<<-1<<endl;
		while(a[l]>=b[r]){
			if(c[l]!=c[r]){
				cnt+=b[r]-max(b[r+1],a[l-1]);
			}
			r--;
		}
//		cout<<l<<' '<<r<<' '<<cnt<<endl;
		while(a[l]<b[r]){
			if(c[l]!=c[r]){
				cnt+=a[l]-max(b[r+1],a[l-1]);
			}
			l++;
		}
//		cout<<l<<' '<<r<<' '<<cnt<<endl;
	}
	printf("%lld",cnt);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
