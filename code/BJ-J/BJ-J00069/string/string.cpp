#include<bits/stdc++.h>
using namespace std;
struct Node{
	int g;
	char c;
}a[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin >> n;
	char s;
	cin >> a[1].g >> s >> a[1].c;
	long long len=a[1].g;
	for(long long i=1;i<=n;i++){
		len+=a[i].g;
		cin >> a[i].g >> s >> a[i].c;
	}
	long long i=0,j=0,cnt=0;
	while(i<=n&&j<=len/2){
		i++;
		for(long long k=1;k<=a[i].g;k++){
			j++;
			long long x=len+1-j;
			char y;
			long long ans=0;
			for(long long w=1;w<=n;w++){
				if(ans+a[w].g>=x){
					y=a[w].c;
					break;
				}else{
					ans+=a[w].g;
				}
			}
			if(y!=a[i].c){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}