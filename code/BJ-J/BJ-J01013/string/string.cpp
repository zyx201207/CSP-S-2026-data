#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
char c[N];
long long ans=0;
int main()
{
	deque<int> q;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		q.push_back(i);
	}int st=1,sp=n;
//	cout<<st<<' '<<sp<<' '<<a[st]<<' '<<a[sp]<<' '<<c[st]<<' '<<c[sp]<<' '<<ans<<' '<<endl;
	while(q.size()>1){
		int x=a[st],y=a[sp];
		if(x>y){
			if(c[st]!=c[sp]) ans+=a[sp];
			a[st]-=a[sp];
			sp--;
			q.pop_back();
//			cout<<st<<' '<<sp<<' '<<a[st]<<' '<<a[sp]<<' '<<c[st]<<' '<<c[sp]<<' '<<ans<<' '<<endl;
		}
		else if(x==y){
			if(c[st]!=c[sp]) ans+=a[sp];
			st++;
			sp--;
			q.pop_front();
			q.pop_back();
//			cout<<st<<' '<<sp<<' '<<a[st]<<' '<<a[sp]<<' '<<c[st]<<' '<<c[sp]<<' '<<ans<<' '<<endl;
		}
		else{
			if(c[st]!=c[sp]) ans+=a[st];
			a[sp]-=a[st];
			st++;
			q.pop_front();
//			cout<<st<<' '<<sp<<' '<<a[st]<<' '<<a[sp]<<' '<<c[st]<<' '<<c[sp]<<' '<<ans<<' '<<endl;
		}
    }
    cout<<ans;
    return 0;
}