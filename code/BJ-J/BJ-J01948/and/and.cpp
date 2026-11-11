#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n[1000001],m[10000001],i,x[1000001],a,b,erjinzhi=0,sum=0;;
    cin>>a>>b;
    for( i=1;i<=a;i++){
        cin>>n[i];
        for(double j=0.1;n[i]==0;j*=10){
            erjinzhi=n[i]%2*10*j+erjinzhi;
            m[i]=erjinzhi ;
            if (n[i]==(1||3||7||15||31||63||127||255||511||1023||2047)){
                sum+=1;
                x[i]=n[i];
                if(x[i]>x[i-1]){
                    swap(x[i],x[i-1]);
                }
                
            }
            
            
        }
        if(sum!=0){
            cout<<x[i];
        }else{
            cout<<n[i];
        }
        
        
        
    }
 
    
    return 0;
}
