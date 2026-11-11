//maybe this problem is easy
//but the date is big
#include<cstdio>//<-The code need read a lot of date so I include this
using namespace std;
int n,m,r,a[500005],q[500005],ans[300005];//,la[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        r=1;
        //for(int i=1;i<=n;la[i]=-1,i++);
        for(int j=i;j<=n;j++){
            q[r]=a[j];
            r++;
            //if(la[a[j]]!=-1){//serach in memery
            //    r=la[a[j]]+1;
            //}else{
                //la[a[j]]=r;//remember the first apper
            //}
            for(int k=r-2;k>=0;k--){//old V
                if(q[k]==a[j]){
                    r=k+1;
                    break;
                }
            }
            //for(int k=1;k<r;k++)cout<<q[k]<<' ';
            //cout<<"\n";
        }
        for(int i=1;i<r;i++){
            ans[q[i]]++;
        }
        //cout<<"end\n";
    }
    for(int i=1;i<=m;i++)printf("%d ",ans[i]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}//That is difficult:(
