//GZ-J00507 陈俊瑞 兴义市弘毅中学
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
#define maxn 200005
int n;
struct sub{
	ll a;
	char c;
};
sub s[maxn];
ll pre[maxn],ans=0;
string b;
ll sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i].a>>s[i].c;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=s[i].a;j++)
		b+=s[i].c;
		sum+=s[i].a;
	}
	for(int i=0;i<=sum/2;i++){
		if(b[i]!=b[sum-i-1]){
			ans++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
