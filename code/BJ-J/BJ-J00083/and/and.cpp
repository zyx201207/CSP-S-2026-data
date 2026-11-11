#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
long long n,m;
struct node{
    long long num;
    long long value;
};
node a[1000000];
long long ans;
long long countvalue(long long x){
    long long y[40];
    long long k=0;
   // cout<<2<<endl;
    while(x>0){
        y[k++]=x%2;
        x/=2;
    }
   // cout<<3<<endl;
    long long  num=0;
    long long b=0;
    for(long long i=0;i<k;i++){
        num+=(y[i]*pow(2,b));
        b++;
    }
   // cout<<4<<endl;
    return num;
}
bool cmp(node a,node b){
    return a.value>b.value;
}
bool vis[1000000];
void dfs(int step,long long x){
    if(step==m+1){
        ans=max(ans,x);
        return;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=true;
            dfs(step+1,x&a[i].num);
            vis[i]=false;
        }
    }
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    if(n<=10 || m>=n-3 || m<=3){
		for(long long i=1;i<=n;i++){
			cin>>a[i].num;
			//cout<<1<<endl;
			//a[i].value=countvalue(a[i].num);
			//cout<<a[i].value<<endl;
		}
		dfs(1,2147483647);
		cout<<ans;
		
	}else{
		for(long long i=1;i<=n;i++){
			cin>>a[i].num;
			//cout<<1<<endl;
			a[i].value=countvalue(a[i].num);
			//cout<<a[i].value<<endl;
		}
		//cout<<"input ok"<<endl;
		sort(a+1,a+n+1,cmp);
		// cout<<"sort ok"<<endl;
		ans=2147483647;
		for(int i=1;i<=m;i++){
			//cout<<a[i].num<<" ";
			ans &= a[i].num;
		}
		cout<<ans;
	}
    return 0;
}
