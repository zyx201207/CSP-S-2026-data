#include<bits/stdc++.h>
using namespace std;
long long n,m,asw,ls;
long long a[200050];
bool cmp(int x,int y){
	return x>y;
}
long long s[]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	asw=a[1];
	for(int i=2;i<=m;i++){
		asw&=a[i];
	}
	cout<<asw;
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
long long n,m,asw=0;
long long a[200050];
long long s[200050];
void dfs(int step,int z,int y){
	if(step==z+1){
		if(y==m){
		long long ls=0,f=0;
		for(int i=1;i<=n;i++){
			if(f==0&&ls==0){
				f=1;
				ls=s[i]*a[i];
			}
			ls&=s[i]*a[i];
		}
		asw=max(asw,ls);
		}
		return;
	}
	if(y<m){
		s[step]=1;
		dfs(step+1,z,y+1);
	}
	s[step]=0;
	dfs(step+1,z,y);
}
int main(){
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(0,n,0);
	cout<<asw;
    return 0;
}*/

