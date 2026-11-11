#include<cstdio>
#include<vector>
using namespace std;
FILE*p;int ls;
unsigned int in[200010];
struct stu{unsigned int n;int n1;};
vector <stu>out;
int main(){
    p=freopen("and.in","r",stdin);
    p=freopen("and.out","w",stdout);
    int m,n;
    scanf("%d %d",&n,&m);
    unsigned int i,j,get;
    for(int i=0;i<n;i++){
        ls=scanf("%d",in+i);
    }
    //the num of 1 get more
    for(int i=0;i<=n;i++){
        int sum1=0;
        get=in[i];
        for(i=0;i<=29;i++){
            if(get&&(1<<i)==1)sum1++;
        }
        stu a;a.n=in[i];a.n1=sum1;
        if(out.size()==0){
            out.push_back(a);
        }
        else{
            if(sum1>=out.back().n1&&out.size()<m){
                for(auto j=out.end();j!=out.begin();j--){
                    auto k=j+1;
                    if((*j).n1<=sum1&&sum1<=*k.n1){
                        out.insert(a,j);
                    }
                }
            }
        }
    }
    int ans=in[0].n;
    for(i=1;i<m;i++){
        ans&out[i].n;
    }
    printf("%d",ans);
    return 0;
}