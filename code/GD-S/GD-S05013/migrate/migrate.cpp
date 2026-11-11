#include<iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

class arr2{
    ull **arr;
    size_t m,n;
public:
    arr2(size_t m,size_t n):m(m),n(n){arr=new ull*[m];for(int i=0;i<m;i++)arr[i]=new ull[n];for(int i=0;i<n;i++)for(int j=0;j<n;j++)arr[i][j]=0x3f3f3f3f;}
    ~arr2(){for(int i=0;i<m;i++)delete[]arr[i];delete[]arr;}
    ull* operator[](size_t i){return arr[i];}
};

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
int c,T;cin>>c>>T;
for(int t=0;t<T;t++){
    ull n,d;cin>>n>>d;
    arr2 dis(n+1,n+1);
    {
        ll*x=new ll[n];
        //int*dis=new size_t[n-1];        //dis[i]表示第i个岛屿与第i+1个岛屿之间的距离
        for(int i=0;i<n;i++)cin>>x[i];
        dis[1][0]=dis[0][1]=x[0];
        for(int i=1;i<n;i++)dis[i+1][i]=dis[i][i+1]=x[i]-dis[i-1][i];
        delete[] x;x=nullptr;
    }
    int cnt=0;
    arr2 minw(n+1,n+1),countof(n+1,n+1);
    for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++){
        if(dis[i][k]+dis[k][j]<dis[i][j]){
            minw[i][j]=dis[i][k]+dis[k][j];
            if(countof[i][j]==2)cnt--;
            countof[i][j]=0;
        }
        if(dis[i][k]+dis[k][j]==dis[i][j]){
            if(countof[i][j]==2)cnt--;
            countof[i][j]++;
            if(countof[i][j]==2)cnt++;
        }
    }
    cout<<cnt<<endl;
}
return 0;
}
