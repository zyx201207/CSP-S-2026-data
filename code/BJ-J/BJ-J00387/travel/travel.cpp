#include<bits/stdc++.h>
using namespace std;
unsigned long long c1,c2_1,c3,c4_1;
char c2_2,c4_2;
bool ok(){
    if(c2_2=='D') c2_2='E';
    if(c4_2=='D') c4_2='E';
    if(abs(c4_2-c2_2)==1) return true;
    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>c2_1>>c2_2>>c3>>c4_1>>c4_2;
    //cout<<c1<<endl<<c2_1<<endl<<c2_2<<endl<<c3<<endl<<c4_1<<endl<<c4_2<<endl;
    //cout<<(c1==c3)&&(c2_1 == c4_1)<<endl;
    cout<<(bool)(c1==c3);
    cout<<(bool)((c1==c3)&&(c2_1 == c4_1));
    cout<<(bool)(((c1==c3)&& (c2_1==c4_1))&&((c2_2<='C' && c4_2<='C') || ('D'<=c2_2 && c2_2<='F' && 'D'<=c4_2 && c4_2<='F')));
    cout<<(bool)(((c1==c3)&& (c2_1==c4_1))&&((c2_2<='C' && c4_2<='C') || ('D'<=c2_2 && c2_2<='F' && 'D'<=c4_2 && c4_2<='F')) && ok());

}
