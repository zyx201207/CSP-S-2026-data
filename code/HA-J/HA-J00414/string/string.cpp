//2
#include<bits/stdc++.h>
#include<vector>
using namespace std;
long long n,ll=0,sum=0;
int dir=0;
struct nd{
	long long st,en;
	char s;
};
vector<nd> v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		v.push_back({ll+1,ll+a,c});
		ll+=a; 
		dir++;
	}
	int l=0,r=dir-1;
	for(long long i=1;i<=ll/2;i++){
		long long j=ll+1-i,t;
		char x,y;
		if(i>v[l].en){
			l++;
		}
		x=v[l].s;
		if(j<v[r].st){
			r--;
		}
		y=v[r].s;
		t=min(v[l].en-i+1,min(j-v[r].st+1,ll/2-i+1));
		if(x!=y){
			sum+=t;
		}
		i+=t-1;
	}
	cout<<sum;
	return 0;
}
