
#include<bits/stdc++.h>
using namespace std;
int a,b[1000086],c,d,sum,sum1,r,l;

int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cin>>a>>c;
for(int i=1;i<=a;i++){
    cin>>b[i];
}
for(int i=1;i<=a;i++){

    for(int j=i;j<=c+i;j++){

        cout<<b[i]<<" "<<b[j]<<endl;
        sum1=(b[i] & b[j]);

    }


    if(sum1>sum){
            sum=sum1;
    }
    sum1=0;
}
cout<<sum;
return 0;
}
