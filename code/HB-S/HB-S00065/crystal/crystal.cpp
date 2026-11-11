#include<bits/stdc++.h>
using namespace std;

int a[500000];
int n,m;

int w;
void sort(int i,int j){
    if(i<j){
        if(a[i]>a[j]){
            w=a[i];
            a[i]=a[j];
            a[j]=w;
        }
        sort(i+1,j);
    }
}

int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %d",&n,&m);
    int w=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        w=i;
        while(a[w]>a[i]){
            w--;
        }
        sort(w+1,i);
    }
    int sum=0;
    long long c=0,d=0;
    for(int i=1;i<n;i++){
        d=a[i]-a[i-1];
        if(c<=m)sum=i;
        else break;
        c+=d*i;
    }
    printf("%d",sum);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
