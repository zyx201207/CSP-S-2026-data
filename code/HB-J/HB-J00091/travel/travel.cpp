#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char cr[13];
    for(int i=0;i<=9;i++){
        cin>>a[i];
    }
     if(cr[0]==cr[5]){
        if(cr[1]==cr[5]){
            printf("1");
            if(cr[2]==cr[7]&&cr[3]==cr[8]){
                printf("1");
                if((cr[4]>='A'&&cr[4]<='C')&&(cr[9]>='A'&&cr[9]<='C'))
                {
                    printf("1");
                    if(cr[4]-cr[9]==1||cr[9]-cr[4]==1) printf("1");
                    else printf("0");
                }
                else if(cr[4]>='D'&&cr[4]<='F'&&cr[9]>='D'&&cr[9]<='F')printf("11");
                else printf("00");
            }
            else printf("000");
        }
        else printf("0000");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
