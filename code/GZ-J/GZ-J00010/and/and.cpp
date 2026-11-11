//GZ-J100010 六盘水市第四实验中学 彭荣锦
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300000],maxa=-1;
void jb(long long ans,long long num,long long d){
	if(ans==m){
		maxa=max(maxa,num);
		return;
	}
	for(long long i=d+1;i<=n;i++){
		jb(ans+1,num&a[i],i);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		jb(1,a[i],i);
	}
	cout<<maxa;
	return 0;
} 
