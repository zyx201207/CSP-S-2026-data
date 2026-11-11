#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;

}
int a[10000005]={0};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int s=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]==a[j]&&i!=j){
                s=a[i];
            }

        }

    }

    sort(a,a+n,cmp);
    int max=a[0];
    for(int i=1;i<=m-1;i++){
        max=max&a[i];
    }
    if(s>max){
        cout<<s;
        return 0;
    }else{
    cout<<max;
    return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
