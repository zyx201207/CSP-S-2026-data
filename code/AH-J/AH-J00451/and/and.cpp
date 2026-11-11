#include<iostream>
#include<cmath>
using namespace std;
long long n,m,a[200005],mx[50],fa[50],sum;
void father(){
    fa[0]=1;
    fa[1]=2;
    for(int i=2;i<=31;i++){
        fa[i]=fa[i-1]*2;
    }
}
void str1 (int c){
    for(int i=31;i>=0;i--){
        if(fa[i]<=c){
            mx[i]++;
            c-=fa[i];
        }
    }
}
bool check(int c,int d){
    for(int i=31;i>=0;i--){
        if(fa[i]<=c){
            c-=fa[i];
            if(i==d){
                return 1;
            }
        }
        if(d>i){
            return 0;
        }
    }
}
void shanchu(int c){
    for(int i=31;i>=0;i--){
        if(fa[i]<=c){
            mx[i]--;
            c-=fa[i];
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    father();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        str1(a[i]);
    }
    for(int i=32;i>=0;i--){
        if(mx[i]>=m){
            sum+=fa[i];
            int k=1;
            for(int j=1;j<=n;j++){
                if(check(a[j],i)==1){
                    a[k++]=a[j];
                }else{
                    shanchu(a[j]);
                }
            }
            n=k-1;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
