#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
struct s{
	int a;
	int b;
}f[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	char s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>f[i].a;
		cin>>s;
		f[i].b=s-'a'+1;
	}
	int cnt=0,sum=0;
	for(int i=1;i<n;i++){
		sum=f[i].a;
		while(sum>0&&n!=i){
			if(f[i].b!=f[n].b){
				if(sum>=f[n].a){
					sum-=f[n].a;
					cnt+=f[n].a;
					n--;
				}
				else{
					f[n].a-=sum;
					cnt+=sum;
					sum=0;
				}
			}
			else{
				if(sum>=f[n].a){
					sum-=f[n].a;
					n--;
				}
				else{
					f[n].a-=sum;
					sum=0;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
} 

