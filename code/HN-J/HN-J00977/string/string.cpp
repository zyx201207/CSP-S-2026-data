#include<bits/stdc++.h>
using namespace std;
struct z{
	int m;
	char ch;
}a[200005];
long long c[30];
long long d[30];
long long n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long l1=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i].m;
		cin>>a[i].ch;
		l1+=a[i].m;
		
		d[a[i].ch-'a'+1]+=a[i].m;
		
	}
	long long l2=0,l3=l1/2+l1%2,j=n;
	for(long long i=1;i<=n;i++){
		l2+=a[i].m;
		c[a[i].ch-'a'+1]+=a[i].m;
		if(l2>=l3){
			j=i;
			c[a[i].ch-'a'+1]=c[a[i].ch-'a'+1]-l2+l3;
			break;
		}
	}
	long long s1=0;
	for(long long i=1;i<=26;i++){
		s1+=d[i]-c[i];
		
	}
	cout<<s1;
	return 0;
}
