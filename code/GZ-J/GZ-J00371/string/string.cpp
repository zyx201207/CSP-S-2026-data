//GZ-J00371 代清宸 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
const long long M=200005;
long long a[M];
char c[M];
string s;
long long n;
long long sum,cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(long long i=0;i<n;i++){
		scanf("%lld",&a[i]);
		cin>>c[i];
		for(long long j=sum;j<a[i]+sum;j++){
			s[j]=c[i];
		}
		sum+=a[i];
	}
	if(sum%2==0){
		for(int i=sum/2;i<sum;i++){
			if(s[i]!=s[sum-i-1]) cnt++;
		}
	}
	else if(sum%2==1){
		for(int i=sum/2+1;i<sum;i++){
			if(s[i]!=s[sum-i-1]) cnt++;
		}
	}
	printf("%lld\n",cnt);
	return 0;
}
