#include<bits/stdc++.h>
using namespace std;
long long n,a,h,ans;
char c,m[1000006];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(long long i=1;i<=n;i++){
		cin >>a>>c;
		for(long long j=1;j<=a;j++){
			h++;
			m[h]=c;
		}
	}
	for(long long i=1;i<=h/2;i++){
//		cout<<m[i]<<" "<<m[h-i+1]<<endl;
		if(m[i]!=m[h-i+1]){
			ans++;
		}
	}
//	for(long long i=1;i<=h;i++){
//		cout<<m[h]<<" ";
//	}
	cout<<ans;
	return 0;
} 
