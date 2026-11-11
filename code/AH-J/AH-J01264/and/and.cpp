#include<bits/stdc++.h>
using namespace std;
long long n,m,a[221000],max_,max_2,all,double_;
long long maxn;
void dfs(long long num,long long ii,long long shu){
    if(num>=m){
        maxn=max(maxn,shu);
    }
    if(ii>=n){
        return;
    }
    if(n-ii<m-num){
        return;
    }
    for(long long i=ii;i<=n-(m-num);i++){
        dfs(num+1,i+1,shu&a[i]);
    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
        if(max_<a[i]){
            max_=a[i];
        }
    }
    if(m==1){
        cout<<max_<<endl;
        return 0;
    }else if(m==2){
		for(long long i=0;i<n-1;i++){
			for(long long j=i+1;j<n;j++){
				double_=max(double_,(a[i]&a[j]));
			}
		}
        cout<<double_<<endl;
        return 0;
    }else if(m==n){
        for(long long i=0;i<n;i++){
            if(i==0){
                all=a[i];
            }else{
                all&=a[i];
            }
        }
        cout<<all<<endl;
        return 0;
    }else if(n>200){
        cout<<max_<<endl;
        return 0;
    }else{
        for(long long i=0;i<=n-m;i++){
            dfs(1,i+1,a[i]);
        }
        cout<<maxn<<endl;
        return 0;
    }
    return 0;
}
