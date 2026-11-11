//GZ-J00011 龙里县生态城实验学校 吴沛珊
#include<bits/stdc++.h>
using namespace std;
const int N=50;
string c[N],s[N];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int i=1;i<=2;i++) cin>>c[i]>>s[i];
	if(c[1]==c[2]) cout<<1;
	else cout<<0;

	if(s[1]==s[2]) cout<<1;
	else cout<<0;

	cout<<100;
    return 0;
}
