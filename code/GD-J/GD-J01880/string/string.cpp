#include<bits/stdc++.h>
using namespace std;
long long sum=0,bsum=0,asum=0,ans=0;
struct j{
	long long c;
	string s;
};
j r[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("srting.out","w",stdout);
	int n;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r[i].c;
		cin>>r[i].s;
		sum+=r[i].c;
	}
	bsum=sum/2;
	int l=1,rp=n;
	while(l<=rp){
		if(r[l].s==r[rp].s){
			if(r[l].c>r[rp].c){
				r[l].c=r[l].c-r[rp].c;
				rp--;
			}
			else if(r[l].c<r[rp].c){
				r[rp].c=r[rp].c-r[l].c;
				l++;
			}
			else{
				l++;
				rp--;
			}
		}
		else{
			if(r[l].c==r[rp].c){
				ans+=r[l].c;
				l++;
				rp--;
			}
			else if(r[l].c>r[rp].c){
				ans+=r[rp].c;
				r[l].c-=r[rp].c;
				rp--;
			}
			else{
				ans+=r[l].c;
				r[rp].c-=r[l].c;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
