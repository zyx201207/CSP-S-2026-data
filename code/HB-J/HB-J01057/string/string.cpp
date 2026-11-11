#include<bits/stdc++.h>
using namespace std;
struct str{
    long num;
    char ch;
}st[100005];
/*
char sch(int n){
    int num=0;
    for(int i=0;i<n;i++){
        if(num+st[i].num>=n&&st[i].num<n){
            return st[i].ch;
        }
        num+=st[i].num;
    }
}
*/
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long ans=0,mid=0,mid_pos=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%ld %c",&st[i].num,&st[i].ch);
        mid_pos+=st[i].num;
    }
    if(mid_pos%2){
        mid_pos++;mid_pos/=2;
    } else {
        mid_pos/=2;
    }
    for(int i=0;;i++){
        if(mid_pos>st[i].num){
            mid_pos-=st[i].num;
            mid++;
        } else {
            break;
        }
    }
    long left=0,right=n-1,left_pos=1,right_pos=st[right].num;
    while(left<=mid&&right>=mid+1){
        if((st[left].num-left_pos+1)==right_pos){
            if(st[left].ch!=st[right].ch){
                ans+=st[left].num;
                left++;
                right--;
            }
        } else if((st[left].num-left_pos+1)<right_pos){
            if(st[left].ch!=st[right].ch){
                ans+=(st[left].num-left_pos+1);
                right_pos-=(st[left].num-left_pos+1);
                left++;
                left_pos=1;
            }
        } else {
            if(st[left].ch!=st[right].ch){
                ans+=(right_pos);
                left_pos+=right_pos;
                right--;
                right_pos=st[right].num;

            }
        }
    }
    printf("%ld",ans);
    return 0;
}
