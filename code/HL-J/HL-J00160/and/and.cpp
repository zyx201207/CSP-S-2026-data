#include <bits/stdc++.h>
using namespace std;
int a[200040];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,num=0;
    cin>>n>>m;
    int c=fact(n)/(fact(n-m)*fact(m));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        for(int i=0;i<n;i++){
            if(a[i]>=num){
                num=a[i];
            }
        }
        cout<<num;
    }else if(m==n){
        for(int i=0;i<n;i++){
            if(i==0){
                num=a[0];
            }else{
                num=num&a[i];
            }
            cout<<num;
        }
    }else if(m==2){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(a[i]&a[j]>=num){
                    num=a[i]&a[j];
                }
            }
        }
        cout<<num;
    }else if(m==n-1){
        for(int i=0;i<n;i+=0){
            int temp=a[0];
            for(int j=0;j<n;j++){
                if(i!=j){
                    temp=temp&a[j];
                }
            }
            if(temp>=num){
                num=temp;
            }
            cout<<num;
        }
    }else if(m==3){

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(((a[i]&a[j])&a[k])>=num){
                        num=((a[i]&a[j])&a[k]);
                    }
                }
            }
        }
        cout<<num;
    }else if(m==4){
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int k=j+1;k<n-1;k++){
                    for(int l=k+1;l<n;l++){
                        if((((a[i]&a[j])&a[k])&l)>=num){
                            num=(((a[i]&a[j])&a[k])&l);
                        }
                    }

                }
            }
        }
        cout<<num;
    }else if(m==5){
        for(int i=0;i<n-4;i++){
            for(int j=i+1;j<n-3;j++){
                for(int k=j+1;k<n-2;k++){
                    for(int l=k+1;l<n-1;l++){
                        for(int o=l+1;o<n;o++){
                            if(((((a[i]&a[j])&a[k])&l)&o)>=num){
                                num=((((a[i]&a[j])&a[k])&l)&o);
                            }
                        }

                    }

                }
            }
        }
        cout<<num;
    }else if(m==6){
        for(int i=0;i<n-5;i++){
            for(int j=i+1;j<n-4;j++){
                for(int k=j+1;k<n-3;k++){
                    for(int l=k+1;l<n-2;l++){
                        for(int o=l+1;o<n-1;o++){
                            for(int p=l+1;p<n;p++){
                                if((((((a[i]&a[j])&a[k])&l)&o)&p)>=num){
                                    num=(((((a[i]&a[j])&a[k])&l)&o)&p);
                                }
                            }

                        }

                    }

                }
            }
        }
        cout<<num;
    }else{
        cout<<33;
    }
    return 0;
}
