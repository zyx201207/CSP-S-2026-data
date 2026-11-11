#include<bits/stdc++.h>
using namespace std;
    string m[10000001];
    string v[10000001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long a,cnt=1,sum=0;
    char c;
    for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=cnt;j<=cnt+a-1;j++){
			m[j]=c;
		}
		cnt+=a;
	}
	cnt--;
	for(long long y=cnt;y>=1;y--){
		v[cnt+1-y]=m[y];
	}
	for(long long x=1;x<=cnt;x++){
		if(m[x]!=v[x]){
			sum++;
		}
	}
	cout<<sum/2;
    return 0;
}
