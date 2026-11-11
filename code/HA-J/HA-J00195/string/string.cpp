#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long a[N],len;
long long ans;
char ch[N];
long long front,back;
long long g;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		len+=a[i];
	}
//	g=a[1];
//	for(int i=2;i<=n;i++){
//		g=__gcd(g,a[i]);
//	}
//	for(int i=1;i<=n;i++){
//		a[i]/=g;
//		len+=a[i];
//	}
	front=1,back=n;
	for(long long i=0;i<=len/2;i){
		if(front>=back)break;
		if(ch[front]!=ch[back]){
			if(a[front]<a[back]){
				i+=a[front];
				a[back]-=a[front];
				ans+=a[front];
				front++;
			}else if(a[front]==a[back]){
				i+=a[front];
				ans+=a[front];
				front++;
				back--;
			}else{
				i+=a[back];
				a[front]-=a[back];
				ans+=a[back];
				back--;
			}
		}else{
			if(a[front]<a[back]){
				i+=a[front];
				a[back]-=a[front];
				front++;
			}else if(a[front]==a[back]){
				i+=a[front];
				front++;
				back--;
			}else{
				i+=a[back];
				a[front]-=a[back];
				back--;
			}
		}
	}
	cout<<ans;
//	cout<<ans*g<<'\n';
	return 0;
}

