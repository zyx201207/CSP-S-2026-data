#include<bits/stdc++.h>
using namespace std;
const int N=200005;
struct Node {
	unsigned long long val;
	char letter;
};
unsigned long long cnt;
Node a[100000005];
char b[100000005];
int ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].val>>a[i].letter;
	}
	int k=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=a[i].val;j++)
		{
			b[k++]=a[i].letter;
			cnt++;
		}
	}
	for(unsigned long long i=1,j=cnt;i<=j;i++,j--)
	{
		if(b[i]!=b[j]) ans++;
	}
	cout<<ans;
	return 0;
}
