#include<bits/stdc++.h>
using namespace std;
long long n,cnt,ans;
string k;
struct HD{
	long long m,r;
	char b;
}a[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].b;
		for(int j=0;j<a[i].m;j++){
			k+=a[i].b;
		}
		cnt+=a[i].m;
	}
	if(cnt%2==0){
		for(long long i=1;i<=cnt/2;i++){
			if(k[i+cnt/2+1]!=k[cnt/2-i]){
				ans++;
			}
		}
	}else{
		for(long long i=0;i<=cnt/2;i++){
			if(k[i+cnt/2]!=k[cnt/2-i])ans++;
		}
	}
	cout<<ans;
	return 0;
} 
