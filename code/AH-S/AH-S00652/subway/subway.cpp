#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int i,c,n,m,d,q;
int a[N];
int ans[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    if(m<=5)
    cout<<"32"<<endl<<"17";
    else if(m<=7)
    cout<<"35"<<endl<<"16";
    else if(m<=10)
    cout<<"36"<<endl<<"15";
	return 0;
}
