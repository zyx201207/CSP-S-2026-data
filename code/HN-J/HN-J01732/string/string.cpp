#include<bits/stdc++.h>

using namespace std;

struct sb{
	long long l;
	char c;
}a[200010];
long long n,sum,t=1;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char x;
		cin>>a[i].l>>a[i].c;
//		cout<<n<<" ";
	}
	while(n>t){
		if(a[n].l==a[t].l){
			if(a[n].c!=a[t].c)sum+=a[n].l;
			n--;
			t++;
			continue;
		}
		if(a[n].l>a[t].l){
			if(a[n].c!=a[t].c)sum+=a[t].l;
			a[n].l-=a[t].l;
			t++;
			continue;
		}
		if(a[n].l<a[t].l){
			if(a[n].c!=a[t].c)sum+=a[n].l;
			a[t].l-=a[n].l;
			n--;
			continue;
		}
	}
	cout<<sum;
	return 0;
}

