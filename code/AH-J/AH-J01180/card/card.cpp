#include<stdio.h>
#include<vector>
#include<stack>
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout); 
    int n,m;
    scanf("%d %d",&n,&m);
    std::vector<int> a(n+1),ans(m+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        std::stack<int> s;
        std::vector<bool> puted(m+1);
        for(int j=i;j<=n;j++){
            if(puted[a[j]]){
                while(s.top()!=a[j]){
                    puted[s.top()]=0;
                    s.pop();
                }
            }
            else{
                puted[a[j]]=1;
                s.push(a[j]);
            }
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        } 
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;

}