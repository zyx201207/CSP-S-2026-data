#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}x[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].c;
		s+=x[i].a;
	}
	long long l=1,r=n,ans=0;
	s/=2;
	while(l<=r){
		if(x[l].c!=x[r].c){
			if(x[l].a>x[r].a){
				ans+=x[r].a;
				x[l].a-=x[r].a;
				r--;
			}else if(x[l].a<x[r].a){
				ans+=x[l].a;
				x[r].a-=x[l].a;
				l++;
			}else{
				ans+=x[l].a;
				l++;
				r--;
			}
		}else{
			if(x[l].a>x[r].a){
				x[l].a-=x[r].a;
				r--;
			}else if(x[l].a<x[r].a){
				x[r].a-=x[l].a;
				l++;
			}else{
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
