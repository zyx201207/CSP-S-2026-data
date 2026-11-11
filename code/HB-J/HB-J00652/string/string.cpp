#include<bits/stdc++.h>
using namespace std;
long long n,num,ans;
struct node{
	long long a;
	char c;
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		num+=s[i].a;
	}
	long long l=1,r=n,nl=1,nr=num;
	while(nl<nr){
		long long minn;
		if(s[l].a>=s[r].a){ //left>right
			minn=s[r].a;
			s[l].a-=minn;
		}
		else if(s[l].a==s[r].a){ //left=right
			minn=s[r].a;
		}
		else{ //left<right
			minn=s[l].a;
			s[r].a-=minn;
		}
		if(s[l].c!=s[r].c)ans+=minn;
		nl+=minn,nr-=minn;
		if(s[l].a>=s[r].a){ //left>right
			r--;
		}
		else if(s[l].a==s[r].a){ //left=right
			r--,l++;
		}
		else{ //left<right
			l++;
		}
	}
	cout<<ans;
	return 0;
}
//May all the beauty be blessed.
