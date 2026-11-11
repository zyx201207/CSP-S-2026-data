#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

struct aaa{
    unsigned long long a;
    char c;
};

aaa num2[500005];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string str1;
    str1+='1';
    int n;
    scanf("%d",&n);
    int k=0;
    num2[0].c='A';
    for(int i=1;i<=n;i++){
        unsigned long long num;
        char ch;
        scanf("%lld %c",&num,&ch);
        if(ch!=num2[k].c){
            num2[++k].a=num;
            num2[k].c=ch;
        }
        else{
            num2[k].a+=num;
        }
    }
    if(k==1){
        printf("0");
        return 0;
    }
    else if(k==2){
        unsigned long long sum2=0;
        sum2=num2[1].a;
        if(num2[2].a<sum2){
            sum2=num2[2].a;
        }
        printf("%lld",sum2);
        return 0;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=num2[i].a;j++){
            str1+=num2[i].c;
        }
    }
    unsigned long long ans=0;
    unsigned long long p=str1.size();
    p-=1;
    for(int i=1;i<=p/2;i++){
        if(str1[i]!=str1[p]){
            ans++;
        }
        p--;
    }
    printf("%lld",ans);
    return 0;
}
