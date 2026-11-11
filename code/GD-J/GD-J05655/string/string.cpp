#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
    long long cnt=0,t=0;
    cin>>n;
    string s=" ";
    for(int i=1;i<=n;i++)
    {
    	int a;
   	    string b;
		cin>>a>>b;
		t+=a;
   	    for(int j=1;j<=a;j++)s+=b;
    }
    for(int i=1;i<=t;i++)
    {
   	    if(s[i]!=s[t-i+1])cnt++;
    }
    cout<<cnt/2;
//	int n,cnt_changed=0;
//	bool go_jump = 0;
//	long long totol = 0;
//	cin >> n;
//	for(int i=1; i<=n; i++)
//	{
//		cin >> s[i].a >> s[i].b;
//		totol+=s[i].a;
//	}
//	if (totol%2==1) go_jump=1;
//	long long mid=totol/2,sum=0,pos=1,num=0;
//	bool ok=1;
//	while(sum<mid)
//	{
//		sum+=s[pos].a;
//		pos++;
//		if(sum==mid)break;
//		if(sum>mid)
//		{
//			num=mid-sum;
//			ok=0;
//		}
//	}
//	if(go_jump)pos++;
//	int c;
//	int goes=0;
//	while(goes==mid)
//	{
//		if(s[k].b!=s[n-i+1].b)
//		{
//			changed
//		}
//	}
//	cout<<cnt_changed;
//	return 0;
}
