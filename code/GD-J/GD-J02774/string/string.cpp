#include<bits/stdc++.h>
using namespace std;
const int N=2*100000+5;
long long n,a[N],e[N],s[N],len;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		s[i]=len+1;
		len+=a[i];
		e[i]=len;
	}
	long long sum=0;
	for(long long i=1,x=n,y=1;i<=len/2;){
		if(x>1&&len-i+1<=e[x-1])x--;
		if(y<n&&i>=s[y+1])y++;
		if(b[x]!=b[y]){
			sum+=min(len/2-i+1,min((len-i+1-e[x-1]),(s[y+1]-i)));
			i+=min((len-i+1-e[x-1]),(s[y+1]-i));
		}else i+=min((len-i+1-e[x-1]),(s[y+1]-i));
	}
	cout<<sum;
	return 0;
}
