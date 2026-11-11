#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}b[200005];
long long n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
	}
	long long l=1,r=n;
	while(r>l){
		if(b[l].c==b[r].c){
			if(b[l].a<b[r].a){
				b[r].a-=b[l].a;
				l++;
			}else if(b[l].a==b[r].a){
				l++;
				r--;
			}else{
				b[l].a-=b[r].a;
				r--;
			}
		}else{
			if(b[l].a<b[r].a){
				b[r].a-=b[l].a;
				ans+=b[l].a;
				l++;
			}else if(b[l].a==b[r].a){
				ans+=b[r].a;
				l++;
				r--;
			}else{
				b[l].a-=b[r].a;
				ans+=b[r].a;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
