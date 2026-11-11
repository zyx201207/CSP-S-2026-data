#include<bits/stdc++.h>
using namespace std;
char c[200010];
int a[200010];
long long sl[200010];
long long sr[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	long long len=0;
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
		len+=a[i];
	}
	for(int i=1;i<=n;i++){
		sl[i]=sl[i-1]+a[i];
	}
	for(int i=n;i>=1;i--){
		sr[i]=sr[i+1]+a[i];
	}
	long long l=1,r=len,li=1,ri=n,cnt=0;
	while(li<ri&&l<r){
		if(c[li]!=c[ri]){
			if(sl[li]>sr[ri]){
				cnt+=sr[ri]-l+1;
				l=sr[ri]+1;
				r=len-sr[ri];
				ri--;
			}else if(sl[li]<sr[ri]){
				cnt+=sl[li]-l+1;
				l=sl[li]+1;
				r=len-sl[li];
				li++;
			}else if(sl[li]==sr[ri]){
				cnt+=sl[li]-l+1;
				l=sl[li]+1;
				r=len-sl[li];
				li++,ri--;
			}
		}else{
			if(sl[li]>sr[ri]){
				l=sr[ri]+1;
				r=len-sr[ri];
				ri--;
			}else if(sl[li]<sr[ri]){
				l=sl[li]+1;
				r=len-sl[li];
				li++;
			}else if(sl[li]==sr[ri]){
				l=sl[li]+1;
				r=len-sl[li];
				li++,ri--;
			}
		}
	}
	printf("%lld",cnt);
	return 0;
}

