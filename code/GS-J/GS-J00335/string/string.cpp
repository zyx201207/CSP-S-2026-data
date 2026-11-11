#include<bits/stdc++.h>
using namespace std;
char s[200005],d[1000000005];
long long c[200005],n,i,l=0,b=0,r,L;
bool cheak(int len){
	for(i=0;i<l;i++){
		if(i>=l-i-1){
			break;
		}
		if(d[i]!=d[l-i-1]){
			len-=1;
		}
	}
	return len>=0;
}
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(i=1;i<=n;i++){
	cin>>c[i]>>s[i];
	l+=c[i];
	for(int j=1;j<=c[i];j++){
		d[b]=s[i];
		b++;
	}
}
int mid;
L=0,r=l;
while(L<=r){
	mid=(r+L)/2;
	if(cheak(mid)){
		r=mid-1;
	}
	else{
		L=mid+1;
	}
}
cout<<mid;
return 0;
}
