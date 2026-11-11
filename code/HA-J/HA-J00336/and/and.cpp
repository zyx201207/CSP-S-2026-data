#include<bits/stdc++.h>
using namespace std;
int n,a[2007],b,ans=-1;
int choose(int x,int c,int su){
	if(x==0){
		ans=max(ans,su);
		return 0;
    }
	for(int i=c+1;i<=n;++i){
		//cout<<x-1<<" "<<i<<" "<<(su&a[i])<<endl;
		choose(x-1,i,(su&a[i]));
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&b);
	for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
        choose(b-1,i,a[i]);
	}
    printf("%d",ans);
    return 0;
}



