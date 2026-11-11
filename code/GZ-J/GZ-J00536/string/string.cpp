//GZ-J00536，任轩辰，贵阳市南明区李端棻中学
#include<bits/stdc++.h>
using namespace std;
struct b{
	long long a;
	string c;
}abc[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ai;
	long long ans=0;
	string ci;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>abc[i].a>>abc[i].c;
	int l=0,r=n-1;
	while(l<r){
		if(abc[l].c==abc[r].c){
			if(abc[l].a>=abc[r].a){
				abc[l].a=abc[l].a-abc[r].a;
				abc[r].a=0;
			}
			else{
				abc[r].a=abc[r].a-abc[l].a;
				abc[l].a=0;
			}
		}
		if(abc[l].c!=abc[r].c){
			if(abc[l].a>=abc[r].a){
				ans+=abc[r].a;
				abc[l].a=abc[l].a-abc[r].a;
				abc[r].a=0;
			}
			else{
				ans+=abc[l].a;
				abc[r].a=abc[r].a-abc[l].a;
				abc[l].a=0;
			}
		}
		if(abc[l].a==0)
			l++;
		if(abc[r].a==0)
			r--;
	}
	cout<<ans;
	return 0;
}
