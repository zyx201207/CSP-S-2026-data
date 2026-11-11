#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
const int MAXM=3e5+5;
int n,m;
int a[MAXN];
int x[MAXM],ans[MAXM];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        x[a[i]]++;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=m;j++){
            if(x[j]%2!=0)ans[j]++;
        }
        x[a[i]]--;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
// T1 AC
// T2 maybe 40 pts
// T3 50pts
// T4 0pts
// 好不容易让我调出来中文输入法了
// 气笑了200分都没
// S能不能简单点啊
// 还有20分钟
// 反正HB没人整理游记
// 随便写写算了
//switch on the power line
//remember to put on protection
//Lay down your pieces
//and lets begin object creation
//忘了
//parameter intilization
//set up our new world
//and lets begin the simulation
//if im a set of point 
//then i will give you my dimension 
//if im a circle
//then i will give you my circumference
//if im a sine wave
//then you can sit on all my tangents
//if i approach infinity
//then you can be my limitation
//switch my current to AC to DC
//and then blind my vision
//so dizzy so dizzy
//oh we can travel to AD to BC
//then we can unite
//so deeply so deeply
//if i can if can
//忘了
//if im a eggplant
//then i will give you my nutrients
//if im a tomato
//then i will give you my intioxidents
//if im a tabby cat
//then i will purr for your enjoyment
//if im the only god
//then you are the ?? of my existence
//switch my gender
//to F to M
//and then do whatever
//from AM to PM 
//oh switch my role 
//to S to M
//so we can enter
//the trance the trance
//if i can
//if i can
//feel your viberation
//then i can then i can
//finally be completion
//though you have left
//you have left 
//youhaveleft
//you have left 
// you heve left
// youhaveleft
//马上结束了S再写
// 椎名真昼天下第一！
