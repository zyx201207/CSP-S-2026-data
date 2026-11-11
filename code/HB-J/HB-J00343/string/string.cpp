#include<cstdio>
using namespace std;
long long LEFT=0,RIGHT;//limit
FILE *p;int n,a,ls;char c;long long out=0;
struct stu{int n;int start;char c;}in[200010];//2e5
long long left=0,right=-1;//start with 0,stop by right-left<=1
int leftin=0,rightin;//start with 0;
int i,j=0;
bool lgs(long long *steps){//return y/n && steps
    // printf("in lgs:\n");
    long long lsl,lsr;
    lsl=in[leftin+1].start;
    lsr=in[rightin].start-1;
    // printf("lsl=%lld,lsr=%lld\n",lsl,lsr);
    // printf("-l=%lld,-r=%lld\n",lsl-LEFT,RIGHT-lsr);
    if(lsl-LEFT<RIGHT-lsr){
        *steps=lsl-left;
        return 1;
    }else{
        *steps=right-lsr;
        return 0;
    }
}
int main(){
    p=freopen("string.in","r",stdin);
    p=freopen("string.out","w",stdout);
    ls=scanf("%d",&n);
    rightin=n-1;
    for(i=0;i<n;i++){
        ls=scanf("%d %c",&in[i].n,&in[i].c);
        in[i].start=j;j+=in[i].n;
        right+=in[i].n;
    }//for(i=0;i<n;i++){printf("%d||%c\n",in[i].n,in[i].c);}
    RIGHT=right;
    //start
    while(right-left>1){
        // printf("left=%lld,right=%lld\n",left,right);
        long long steps;
        ls=lgs(&steps);
        // printf("lgs return %d\n",ls);
        if(in[leftin].c!=in[rightin].c){out+=steps;}
        left+=steps;
        right-=steps;
        // printf("left=%lld,in[leftin+1].start=%d\nright=%lld,in[rightin].start-1=%d\n",
        // left,in[leftin+1].start,right,in[rightin].start-1);
        if(left>=in[leftin+1].start){leftin++;
        // printf("l++\n");
        }
        if(right<=in[rightin].start-1){rightin--;
        // printf("r++\n");
        }
    }
    printf("%lld",out);
    return 0;
}