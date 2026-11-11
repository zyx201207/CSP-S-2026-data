#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string c1,s1,c2,s2;
bool flag,flag2;
int t1,t2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		flag2;
	}
	else cout<<0;
	flag=1;
	for(int i=0;i<=1;i++) if(s1[i]!=s2[i]) flag=0;
	if(flag&&flag2) cout<<1;
	else cout<<0;
	t1=s1[2];
	t2=s2[2];
	if(flag2&&flag&&(t1<68&&t2<68)||(t1>67&&t2>67)) cout<<1;
	else cout<<0; 
	int ans1=t1-t2,ans2=t2-t1;
	if(flag2&&flag&&(ans1==1&&t1!=67&&t2!=68)||(ans2==1&&t1!=67&&t2!=68)) cout<<1;
	else cout<<0;
	return 0;
} 
