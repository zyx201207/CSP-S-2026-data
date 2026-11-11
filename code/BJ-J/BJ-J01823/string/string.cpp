#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
    long long a;
    char c;
}num[200005];
node num1[200005];
node num2[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long len=0;
    bool z=1;
    for(long long i=1;i<=n;i++){
        cin>>num[i].a>>num[i].c;
        len+=num[i].a;
        if(num[i].a>500) z=0;
    }if(z){
        vector<char> x;
        x.clear();
        for(long long i=1;i<=n;i++){
            for(long long j=0;j<num[i].a;j++){
                x.push_back(num[i].c);
                //cout<<num[i].c;
            }
        }
        //cout<<endl;
        long long ans=0;
        for(long long i=0;i<len/2;i++){
            long long j=0;
            j=len-i-1;
            //cout<<x[j]<<" "<<x[i]<<endl;
            if(x[j]!=x[i]) ans++;
        }
        cout<<ans;
    }else{
        long long i;
        long long x=0;
        long long cnt=0;
        long long cnt_=0;
        for(i=1;i<=n;i++){
            if(x+num[i].a>=len/2) {
                cnt_++;
                num1[cnt_].a=len/2-x;
                num1[cnt_].c=num[i].c;
                if(x+num[i].a>len/2){
                    num2[1].a=num[i].a-(len/2-x);
                    num2[1].c=num[i].c;
                    cnt++;
                }
                break;
            }else{
                cnt_++;
                num1[cnt_]=num[cnt_];
                x+=num1[cnt_].a;
            }
        }
        i++;
        for(;i<=n;i++){
            cnt++;
            num2[cnt]=num[i];
        }
        if(len%2==1) num2[1].a--;
        //for(long long i=1;i<=cnt_;i++) cout<<"a"<<num1[i].a<<" "<<num1[i].c<<endl;
        //cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        //for(long long i=1;i<=cnt;i++) cout<<"b"<<num2[i].a<<" "<<num2[i].c<<endl;
        //cout<<endl;
        i=1;
        long long j=cnt;
        long long ans=0;
        while(i<=cnt_&&j>0){
            if(num1[i].a<=0){
                i++;
                continue;
            }
            if(num2[j].a<=0){
                j--;
                continue;
            }
            if(num1[i].c==num2[j].c){
                if(num1[i].a>=num2[j].a){
                    num1[i].a-=num2[j].a;
                    num2[j].a=0;
                    j--;
                }else{
                    num2[j].a-=num1[i].a;
                    num1[i].a=0;
                    i++;
                }
            }else{
                if(num1[i].a>=num2[j].a){
                    num1[i].a-=num2[j].a;
                    ans+=num2[j].a;
                    num2[j].a=0;
                    j--;
                }else{
                    num2[j].a-=num1[i].a;
                    ans+=num1[i].a;
                    num1[i].a=0;
                    i++;
                }
            }
        }
        //for(long long i=1;i<=cnt_;i++) ans+=num1[i].a;
        //for(long long i=1;i<=cnt;i++) ans+=num2[i].a;
        cout<<ans;
    }
    return 0;
}
