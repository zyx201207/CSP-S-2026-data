#include<bits/stdc++.h>
using namespace std;

int n,m,a[200015],ans=-1;

void dfs(int number_id,int num,int sum){
    int b=a[number_id] & sum;
    if(number_id==n-1 && num!=m){
		//printf("end....but not\n");
		return;
	}
    if(num==m){
        if(b>ans) ans=b;
        //printf("find answer!! ans=%d b=%d num=%d\n",ans,b,num);
        return;
    }
    for(int i=1;i<n-number_id;i++){
		//printf("number_id=%d,num=%d,b=%d,a=%d\n",number_id,num,b,a[number_id]);
        dfs(number_id+i,num+1,b);
        //printf("OK,i=%d!!\n",i);
    }
    dfs(number_id+1,1,1073741823);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    dfs(0,1,1073741823);
    printf("%d\n",ans);
    return 0;
}
