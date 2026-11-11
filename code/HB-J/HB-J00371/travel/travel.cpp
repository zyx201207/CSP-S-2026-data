#include<bits/stdc++.h>
using namespace std;
char a[100],b[100],c[100],d[100];
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%s %s %s %s",a+1,b+1,c+1,d+1);
    if(a[1]!=c[1]||a[2]!=c[2]){
        printf("0000\n");
        return 0;
    }
    if(b[1]!=d[1]||b[2]!=d[2]){
        printf("1000\n");
        return 0;
    }
    if((b[3]=='D'||b[3]=='F')!=(d[3]=='D'||d[3]=='F')){
        printf("1100\n");
        return 0;
    }
    if((b[3]=='C'||b[3]=='A')&&(d[3]=='C'||d[3]=='A')){
        printf("1110\n");
        return 0;
    }
    printf("1111\n");
    return 0;
}
/*
g++ travel.cpp -o exe -Wall -O2
./exe
diff travel.out travel.ans

*/

/*
Qu(4) Mai(3)<Hao(3) Gu(1) Niang(0) Guang(1) Mang(2) Wan(4) Zhang(4)>
*/

/*
It still comes to the end of the story.
Birds who don't want to fly are crying again and again.
The city will never hear the arguement between us.
Would you feel more free and easy?

It comes back to 12 years ago,
the story before is just in my eyes.
You are under a hat since I looks a little shy.
But during the first meet,
you says that you have XianJian
I have a bit gift, I can fly very high.

How TianZhen I was, how GuaJianXianWan I do.
But I don't like grown-ups, I'm disable to sort.
I'm not for money, but for my future,
I want the sound of my song can get batter and batter.

Do you know?
Beside my dad,
you are the best man I had met.
But the WaWa in white(?),
must grow up with the time.
More and more disappointment let my trustment to you disappear.
*/