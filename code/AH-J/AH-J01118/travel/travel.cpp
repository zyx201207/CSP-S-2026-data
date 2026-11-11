#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int t1,t2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	int lenc1=c1.size(),lenc2=c2.size();
	for(int i=lenc1-1;i>=0;i--)
		t1=t1*10+(c1[i]-48);
	for(int i=lenc2-1;i>=0;i--)
		t2=t2*10+(c2[i]-48);
	if (t1!=t2){
		cout<<"0000";
		return 0;
	}else
		cout<<1;
	t1=0;
	t2=0;
	int lens1=s1.size(),lens2=s2.size();
	for(int i=lens1-2;i>=0;i--)
		t1=t1*10+(s1[i]-48);
	for(int i=lens2-2;i>=0;i--)
		t2=t2*10+(s2[i]-48);
	if (t1!=t2){
		cout<<"000";
		return 0;
	}else
		cout<<1;
	int t3=int(s1[lens1-1]),t4=int(s2[lens2-1]);
	if (t3<=67&&t4<=67||t3>67&&t4>67)
		cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if (abs(int(t3)-int(t4))==1)
		cout<<1;
	else
		cout<<0;
	return 0;
}
