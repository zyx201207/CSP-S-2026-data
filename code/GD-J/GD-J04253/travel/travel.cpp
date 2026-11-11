#include <bits/stdc++.h>
#define int long long
#define rk(i,l,r) for(int i = l;i<=r;++i)
#define rp(i,r,l) for(int i = r;i>=l;--i) 
using namespace std;
string s1,s2,s3,s4;
int bc[110]; 
bool ck()
{
	int l1 =s2.size(),l2=s4.size();
	if(l1!=l2)return 1;
	rk(i,0,l1-2)
	{
		if(s2[i]!=s4[i])return 1;
	}
	return 0;
}
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bc['A']=bc['B']=bc['C']=1,bc['D']=bc['F']=114514;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3)
	{
		cout<<"0000"<<endl;
		return 0;
	 } 
	 if(ck())
	 {
	 	cout<<"1000"<<endl;
		return 0;
	 }
	 if(bc[s2[s4.size()-1]]!=bc[s4[s4.size()-1]])
	 {
	 	cout<<"1100"<<endl;
		return 0;
	 }
	 if(abs(s2[s4.size()-1]-s4[s4.size()-1])!=1)
	 {
	 	cout<<"1110"<<endl;
		return 0;
	 }
	 cout<<"1111"<<endl;
	return 0;
}
