#include <bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char b[200005];
char c[10];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    int j=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        scanf("%s",c+1);
        while(a[i]){
            b[j]=c[1];
            j++;
            a[i]--;
        }
    }
    int m=j-1,ans=0;
    /*for(int i=1;i<=m;i++){
        printf("%c",b[i]);
    }*/
    int l=1,r=m;
    while(l<r){
        //printf("%c %c\n",a[l],a[r]);
        if(b[l]!=b[r]){
            ans++;
        }
        l++;
        r--;
    }
    printf("%d",ans);
	return 0;
}

