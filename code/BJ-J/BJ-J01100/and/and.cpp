#include<iostream>
using namespace std;
int main (){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    int a[200000];
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    //for(int i=0;i<n;i++){
    //    cout<<a[i];
    //}

    //int sumax=0;
    //int sumaxt=0;
    int sum;

    int way;
    //int t1=1,t2=1;
    //for(int i=0,i<m;i++){
    //    t1*=n-i;
    //}
    //for(int i=m,i>0;i--){
    //    t2*=i;
    //}
    way=n-m+1;
    int ma=0;
    for(int i=0;i<way;i++){
        sum=a[i];
        for(int j=i;j<m+i;j++){
            sum&a[j];
        }
        if(sum>ma){
        ma=sum;
        }
    }

    //for(int i=0;i<m;i++){
    //    sumax=0;
    //for(int j=0;j<n;j++){
    //        if(a[j]>sumax){
    //            sumax=a[j];
    //            sumaxt=j;
    //        }
    //    }
    //    a[sumaxt]=0;
    //    if(i=0){
    //        sum=sumax;
    //    }else{
    //        sum&sumax;
    //    }

    //}

    cout<<sum;
    return 0;
}