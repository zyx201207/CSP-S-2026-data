#include <bits/stdc++.h>
using namespace std;
long long a[514514];
int main(){ 
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout); 
    long long n,m;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){scanf("%lld",&a[i]);}
    sort(a+1,a+n+1);
    int l=1,r=1,sum=a[1],cnt=1;
    while(r<=n){
        if(l==r) {r++;sum+=a[r];continue;}
        if((a[r]*(r-l+1)-sum)<=m){
            cnt=max(cnt,r-l+1);
            r++;sum+=a[r];continue;
        }
        else{sum-=a[l];l++;}
    }
    printf("%d",cnt);
    return 0;
}












/*
========我爱 vim========
我如何才能在患有智力障碍的情况下配置vim
我为何要在在患有智力障碍的情况下使用vim

=======某人的情书=======
千寻，见字如面
在这近乎犬式的追求中，更多其实是为赋新词强说愁一般的演绎。我追求的与其说是你，更不如说是那种飘渺的，求而不得，怅然若失的情绪。不过是一个生性薄凉的少年，为感而哀的滋味，而无病呻吟罢了。
而在昨日，你告诉我这是秋天最后一个节气。兜兜转转一个春秋已经过去了，秋蝉哀鸣，万花凋落。出于对这暮秋之景的一种迷恋，也明白我再也等不到下个秋天，促使喜欢残月，落叶，满足我对一次离别的所有期许。但你似乎会错了意，只留给我了一个消失在走廊的背影和微信的感叹号。
我也明白这场糟糕的演出，至少得有一个明晰的结尾，尽管美女与野兽谁也没送出自己的玫瑰。希望能看完，拜托了千寻，别让我一个人唱完这场独角戏。

==========追忆==========
我常常追忆过去
生命瞬间定格在脑海，我将背后的时间裁剪、折叠、卷曲、揉捻成天上朵朵白云。
云朵之间亦有分别，积云厚重，而卷云飘渺。生命里震撼的场景掠过我的思绪便一生难以忘怀，而更为普通平常的记忆在时间的冲刷下只留下些许残骸。追忆宛如入梦，太过清楚则无法愉悦自己的幻想，过分模糊又将坠入虚无。只有薄雾间的山水，面纱下的女子，那恰到好处的朦胧，才能满足我对美的苛求。
追忆总在不经意间将我裹进泛黄的纸页里。分别又重聚的朋友，推倒又重建的街道，种种线索协助着我从一个具体的时刻出发沿时间的河逆流而上。曾经的日子无法重来，我只不过是一个过客。但我仍然渴望着在每一次追忆之旅中留下闲暇时间，在一个场景前驻足，在岁月的朦胧里瞭望过去的自己。感受尽可能多的甜蜜，美好的时光曾流经我的身体，我便心满意足
过去已经凝固，我带着回忆向前，只是时常疏于保管。回忆也在变换着各自的形态，这给我的追忆之旅带来些许挑战。
我该在哪里停留？我问我自己。

===♪The cake is a lie♪==
This is a trimph
I'm making a note here
HUGE SUCCESS
it's hard to overstate my satisfaction
Aperture Science
We do what we must because we can
for the goods all of us
except the ones who're dead
There's no sence crying over every mistake
You can keep on trying till ran out of cake
Now the science gets done
You make a neat gun
for the people who are still alive
I'm not even angry
I've being so sincere right now
even you broke my heart and killed me
And tore me to pieces
And threw every pieces into a fire
As they bornt it hurt because
i was so happy for you
Now sense of data draw a beautful line
We are out of beta we are releasing on time
Now the science gets done
You make a neat gun
for the people who are still alive
(continue)

========================
♪Go to make some new disasters♪
♪That's what i'm counting on♪

========================
Es ist auf.

========================
Typo
*/

