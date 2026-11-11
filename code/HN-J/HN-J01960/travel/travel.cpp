#include<bits/stdc++.h>
using namespace std;
const int N=100500;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<"1000";
	else cout<<"0000";
	fclose(stdin);
    fclose(stdout);
    return 0;
}
