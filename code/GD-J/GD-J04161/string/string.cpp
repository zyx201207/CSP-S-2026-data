#include<bits/stdc++.h>
using namespace std;
long long n,l,r,ans;
struct d{
	long long a;
	char c;
}li[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&li[i].a);
		scanf("%s",&li[i].c);
		//cin>>li[i].c;
	}
	l=1;
	r=n;
	ans=0;
	while(l<r){
		if(li[l].a>li[r].a){
			if(li[l].c!=li[r].c){
				ans+=li[r].a;
			}
			li[l].a-=li[r].a;
			r--;
			//cout<<"debug1"<<endl;
		}
		else if(li[l].a==li[r].a){
			if(li[l].c!=li[r].c){
				ans+=li[r].a;
			}
			l++;
			r--;
			//cout<<"debug2"<<endl;
		}
		else if(li[l].a<li[r].a){
			if(li[l].c!=li[r].c){
				ans+=li[l].a;
			}
			li[r].a-=li[l].a;
			l++;
			//cout<<"debug3"<<endl;
		}
	}
	cout<<ans;
	return 0;
}
