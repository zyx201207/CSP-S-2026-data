#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long a;
long long sum=0;
long long answer=0;
cin>>a;
long long b[2][a];
for(long long i=0;i<a;i++){
    cin>>b[0][i];
    sum=sum+b[0][i];
    char v;
    cin>>v;
    b[1][i]=int(v);

} long long start=0;
long long endd=a-1;
if(sum%2!=0){
while(sum>1){
        if(b[0][start]>b[0][endd]){
            if(b[1][start]!=b[1][endd]){
                answer=answer+b[0][endd];
               sum=sum-b[0][endd]*2;

                 b[0][start]=b[0][start]-b[0][endd];
                  endd--;

            }
            else{
                sum=sum-b[0][endd]*2;

                 b[0][start]=b[0][start]-b[0][endd];
                  endd--;
            }
        }
        else{
            if(b[1][start]!=b[1][endd]){
                answer=answer+b[0][start];
               sum=sum-b[0][start]*2;

                 b[0][endd]=b[0][endd]-b[0][start];
                 start++;

            }
            else{
                sum=sum-b[0][start]*2;

                 b[0][endd]=b[0][endd]-b[0][start];;
                 start++;
            }
        }
        }
}
else{
    while(sum){
        if(b[0][start]>b[0][endd]){
            if(b[1][start]!=b[1][endd]){
                answer=answer+b[0][endd];
               sum=sum-b[0][endd]*2;

                 b[0][start]=b[0][start]-b[0][endd];
                  endd--;

            }
            else{
                sum=sum-b[0][endd]*2;

                 b[0][start]=b[0][start]-b[0][endd];
                  endd--;
            }
        }
        else{
            if(b[1][start]!=b[1][endd]){
                answer=answer+b[0][start];
               sum=sum-b[0][start]*2;

                 b[0][endd]=b[0][endd]-b[0][start];
                 start++;

            }
            else{
                sum=sum-b[0][start]*2;

                 b[0][endd]=b[0][endd]-b[0][start];;
                 start++;
            }
        }
        }
}


   cout<<answer;
return 0;}
