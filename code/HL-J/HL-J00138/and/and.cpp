#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N];
long long res;
bool cmp(int x,int y)
{
    return x>y;
}
//string bin(long long x)
//{
//	string s;
//	while(x){
//		s+=x%2+'0';
//		x/=2;
//	}
//	return s;
//}
//long long oct(long long xn,long long yn)
//{
//    string binn=and(bin(xn),bin(yn));
//    long long sum=0;
//    for(int i=0;i<binn.size();i++)
//    {
//        sum+=(binn[i]-'0')*pow(2,i);
//    }
//}
//string and(long long x,long long y)
//{
//    string cx=bin(x);
//    string cy=bin(y);
//    string ss="";
//    for(int i=0;i<min(cx.size(),cy.size());i++)
//    {
//        if(cx[i]==1&&cy[i]==1) re[i]=1;
//        else re[i]=0;
//    }
//    return ss;
//}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    res=a[0];
    for(int i=1;i<m;i++){
    	res=res&a[i];
    }
    cout<<res;
    return 0;
}
