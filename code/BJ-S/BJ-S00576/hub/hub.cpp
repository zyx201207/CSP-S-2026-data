#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[100005],sum,key,mins,num,ans;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		while(n--)
		{
			cin>>num>>key;
			sum+=num;
		}
		cout<<sum/2<<endl;
	}
	return 0;
}
