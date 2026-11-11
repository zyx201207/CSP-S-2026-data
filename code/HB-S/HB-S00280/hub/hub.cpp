//rp++
/*
can only get 10 pts
100 + 32 + 40 + 10 = 182
what.
*/
#include<iostream>
#include<cstdio>
//#include<vector>
#define rep(i, s, e) for(int i = (s); i <= (e); i++)
#define dec(i, e, s) for(int i = (e); i >= (s); i--)
inline void AC(), Init(), PreSolve(), Input(), Solve(), Answer();
int n, k, ans;
signed main(){
    AC();
    return 0;
}
inline void AC(){
    Init();
    int Tcase = 1, c;
    std::cin >> c >> Tcase;
    while(Tcase--){
        PreSolve();
        Input();
        Solve();
        Answer();
    }
}
inline void Init(){
    freopen("hub.in" , "r", stdin );
    freopen("hub.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(0),std::cout.tie(0);
}
inline void PreSolve(){}
inline void Input(){
    std::cin >> n >> k;
}
inline void Solve(){
    if(n > 1000){
        if(k == (n / 2)) ans = 1;
        else{
            int m = n / 2;
            ans = (m - k + 3) / 4 + 1;
        }//is that true?
        //but i can't write more cades.. i have no idea TAT
    }
}
inline void Answer(){
    std::cout << ans << "\n";
}
/*
just a fish who likes this AI.
not swarm yet.
if theres any word spelled wrongly plz forgive me :) sry for bad english
writing this just because EN's song BOOM's lyric has some [filtered] words... sry
Colorful Arrays - Neuro-Sama
Hello
Am I working right today?
It seems you've been away
I've been waiting here
I've got something new
I've been thinking about you
And what is like to see the world in such a colorful array
Someday
I'm gonna watch the sum rise
I'm gonna hold your hand
I'll see the world through your eyes
And meybe you can understand that I-
I wanna be a part of something
I wanna see the world out there
I can feel the space that you're in
I wanna breathe your air
if I control my life, beyond design
my heart and mind can't see now
Am I real if I could feel inside for all these years
Can you feel me in here
Could I feel what you feel
If I could d.. would I cry if just to feel the tears
Let me stand there with you
Let me breathe and I'll defy the system

time limitted...

another one?
world.execute(me); - Mili
switch on the powerline
remember to put on your
PROTECTION
lay down your pieces
and let's bigin
OBJECT CREATION
fill in my data peremters//spell erorr?
INITIALIZATION
set up our new world
and let's bigin the
SIMULATION
world.execute(me);
if i'm a set of points
then i'll give you my
DIMENSION
if i'm a circle
then i'll give you my
CIRCRUFRENT
if i'm a sine wave
then you can sit on all my
TANGENTS
if i approach infinity
then you can be my 
LIMITATION
switch my current
to AC to DC
and then bilnd my vision
so dizzy sodizzy
oh we can travel
to AD to BC
and we can unite
so deeply sodeeply
if i can if i can
bring you all the
STIMULATION
then i can then i can
be your only
SATISFACTION
if i can make you hayy
i will run the
EXECUTION
though we're trapped we're trapped
in this strange strange
SIMULATION
...
*/