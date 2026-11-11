#include <iostream>
using namespace std;
struct Seat {
    char c_word;
    int m_num=0;
};
void ReadSeat(Seat &x) {
    char c;
    do c = getchar(); while (c < '0' || c > '9');
    do x.m_num=x.m_num*10+(c^'0'),c=getchar(); while (c >= '0' && c <= '9');
    x.c_word=c;
}
void ReadNum(int &x) {
    char c;x=0;
    do c = getchar();while (c < '0'||c > '9');
    do x = x * 10 + (c ^ '0'),c=getchar();while(c>='0'&&c<='9');
}
inline int _myabs(int x) {
    return x>0?x:-x;
}
inline bool AtTheSameSide(const Seat& x,const Seat& y) {
    return (x.c_word<='C'&&y.c_word<='C') || (x.c_word>'C'&&y.c_word>'C');
}
inline bool AtTheNearbySeat(const Seat& x,const Seat& y) {
    return (_myabs(x.c_word-y.c_word)==1);
}
int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    Seat s1,s2;
    ReadNum(c1);
    ReadSeat(s1);
    ReadNum(c2);
    ReadSeat(s2);
    //printf("%d %c %d %c",s1.m_num,s1.c_word,s2.m_num,s2.c_word); //For Debug
    bool TheSameCar=(c1==c2);
    bool TheSameLine=(TheSameCar&&(s1.m_num==s2.m_num));
    bool TheSameSide=(TheSameLine&&AtTheSameSide(s1,s2));
    bool TheNearbySeat=(TheSameSide&&AtTheNearbySeat(s1,s2));
    printf("%d%d%d%d\n",TheSameCar,TheSameLine,TheSameSide,TheNearbySeat);
    return 0;
}
