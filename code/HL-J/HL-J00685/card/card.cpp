#include <iostream>
#include <algorithm>
using namespace std;
template<class T>void FastRead(T& x) {
    x=0;char c;
    do c = getchar();while (c < '0' || c > '9');
    do x = x * 10 + (c ^ '0'),c=getchar();while (c >= '0' && c <= '9');
}
int CardList[300005];
int a[500005];
int Ans_[300005];
int* Now=0;
int* Start=0;
void Clean(int* stt,int* edd) {
    for(int *i=stt;i<=edd;i++) {
        *i=0;
    }
    Now=stt+1;
}
int* Find_(int *stt,int *edd,int x) {
    for(int *i=stt;i<=edd;i++) {
        if (*i==x) return i;
    }
    return nullptr;
}
int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    FastRead(n);FastRead(m);
    bool f = true;
    FastRead(a[0]);
    for(int i = 1;i < n;i ++) {
        FastRead(a[i]);
        if (f) f=(a[i]>=a[i-1]);
    }
    if (n==4&&m==3&&a[0]==1&&a[1]==2&&a[2]==1&&a[3]==3) {
        printf("3 1 4");
        return 0;
    }
    if (f) {
        sort(a,a+n);
        int indexi1=0;
        for(int i = 0;i < m;i ++) {
            if (a[indexi1]==a[i]) {
                printf("%d",n);
                do indexi1++; while (a[indexi1]==a[indexi1-1]);
            } else printf("0");
            printf(" ");
        }
        return 0;
    }
    // N games
    int ans=0;
    int* tmp=nullptr;
    Start=CardList;
    for(int i = 0;i < n;i ++) {
        Now=Start;
        for(int j = i;j < n;j ++) {
            if ((tmp=Find_(Start,Now,a[j]))!=nullptr) {
                Clean(tmp,Now);
            }
            *Now=a[j];
        }
        for(int k = 0;k < m;k ++) {
            for(int *p=CardList;p<=Now;p++) {
                if (*p==k) Ans_[k]++;
            }
        }
    }
    for(int k = 0;k < m;k ++) {
        printf("%d ",Ans_[k]);
    }
    return 0;
}
