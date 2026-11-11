#include<cstdio>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char a1[3],b1[4],a2[3],b2[4];
    scanf("%s %s %s %s",a1,b1,a2,b2);
    bool a=a1[0]==a2[0]&&a1[1]==a2[1];
    bool b=a&&(b1[0]==b2[0]&&b1[1]==b2[1]);
    bool c=b&&(b1[2]<'D'&&b2[2]<'D'||b1[2]>='D'&&b2[2]>='D');
    bool d=c&&(b1[2]<'D'&&b2[2]<'D'&&(b1[2]-b2[2]==-1||b1[2]-b2[2]==1)||b1[2]>='D'&&b2[2]>='D'&&(b1[2]-b2[2]==-2||b1[2]-b2[2]==2));
    printf("%d%d%d%d",a,b,c,d);
    return 0;
}