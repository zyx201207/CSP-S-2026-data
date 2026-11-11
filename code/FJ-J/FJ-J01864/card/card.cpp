#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+50;
const long long M=3e5+50;
long long n,m;
long long a[N],s[M];
bool f[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(f,false,sizeof(f));
		for(int j=i+1;j<=n;j++){
			if(f[a[j]]==false){
				f[a[j]]=true;
			}else{
				long long xb=i;
				for(int k=i;k<=j;k++){
					if(a[k]==a[j]){
						xb=k;
						break;
					}
				}
				for(int k=xb;k<j;k++){
					f[a[k]]=false;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(f[a[j]]==true){
				s[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<' ';
	return 0;
}
