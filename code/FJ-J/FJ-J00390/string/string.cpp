#include<bits/stdc++.h>//T2
using namespace std;
int n,a[200001];
long long ans,cnt;
char c[200001];
inline int rd(){
	int k=0,q=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')q=-1;
		c=getchar();
	}while(isdigit(c)){
		k*=10,k+=c-48,c=getchar();
	}
	return k*q;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=rd();
	for(int i=1;i<=n;++i){
		a[i]=rd();
		c[i]=getchar();
	}long long lt=1,rt=n;
	while(lt<rt){
		if(c[lt]==c[rt]){
			if(a[lt]==a[rt]){
				++lt,--rt;
				continue;
			}else if(a[lt]>a[rt]){
				a[lt]-=a[rt];
				--rt;
				continue;
			}else{
				a[rt]-=a[lt];
				++lt;
				continue;
			}
		}else{
			if(a[lt]==a[rt]){
				ans+=a[lt];
				++lt,--rt;
				continue;
			}else if(a[lt]>a[rt]){
				ans+=a[rt];
				a[lt]-=a[rt];
				--rt;
			}else{
				ans+=a[lt];
				a[rt]-=a[lt];
				++lt;
			}
		}
	}cout<<ans;
	return 0;
}
