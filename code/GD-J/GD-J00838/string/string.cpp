#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}v[200005];
long long n,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=1,r=n;
	for(long long i=1;i<=n;i++)cin>>v[i].a>>v[i].c;
	while(l!=r){
		if(v[l].a==v[r].a){
			if(v[l].c!=v[r].c)sum+=v[l].a;
			l++,r--;
		}
		else if(v[l].a>v[r].a){
			if(v[l].c!=v[r].c)sum+=v[r].a;
			v[l].a-=v[r].a;
			r--;
		}
		else {
			if(v[l].c!=v[r].c)sum+=v[l].a;
			v[r].a-=v[l].a;
			l++;
		}
	}
	cout<<sum;
	return 0;
}

