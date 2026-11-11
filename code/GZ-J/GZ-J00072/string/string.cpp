//GZ-J00072 贵阳中天中学 李弈菓
#include<bits/stdc++.h> 
using namespace std;
long long n;
string sy="";
struct l{
	long long nt;
	string s;
	
}sl[10005];
bool b=1;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>sl[i].nt>>sl[i].s;
	}
	for(int i=1;i<=n;i++){
		if(sl[i].s!=sl[i+1].s)b=0;
	}
	if(b){
		cout<<"0";
		return 0;
	}
	/*int l=1,r=n;
	while(l<r){
		if(sl[l].s!=sl[r].s){
			if(sl[l].nt>sl[r].nt)
			{
				
				if(sl[l].nt-sl[r].nt>=sl[r-1].nt)
				{
					if(r==l++)cout<<sl[r].nt;
					r--;
					sl[r].nt+=sl[r+1].nt;
					break;
				}
				cnt+=sl[l].nt;
			}
		}
		if(sl[l].s!=sl[r].s){
			if(sl[l].nt<sl[r].nt)
			{
					
				if(sl[r].nt-sl[l].nt>=sl[l-1].nt)
				{
					if(r==l+1){
						cout<<sl[r].nt;
						return 0;
					}
					l--;
					sl[l].nt+=sl[l+1].nt;
					break;
				}
				cnt+=sl[r].nt;
			}
		}
		if(sl[l].s!=sl[r].s){
			if(sl[l].nt==sl[r].nt)
			{
				cnt+=sl[r].nt;
			}
		}
		if(sl[l].s!=sl[r].s){
			if(sl[l].nt>sl[r].nt)
			{
				
				if(sl[l].nt-sl[r].nt>=sl[r-1].nt)
				{
					l-=2;
				}
				
			}
		}
		if(sl[l].s!=sl[r].s){
			if(sl[l].nt<sl[r].nt)
			{
					
				if(sl[r].nt-sl[l].nt>=sl[l-1].nt)
				{
					r--;	
				}
				
			}
		}
		l++;
		r--;
	}*/
	
		
		
		
		
		/*if(sl[l].s!=sl[r].s){
			if(sl[l].nt<sl[r].nt)
			{
				cnt+=sl[r].nt;
			}
		}
		if(sl[l].s!=sl[r].s){
			if(sl[l].nt==sl[r].nt)
			{
				cnt+=sl[r].nt;
			}
		}
		l++;
		r--;*/
	
	
	for(int i=1;i<=n;i++){
		while(sl[i].nt--){
			sy+=sl[i].s;
		}
	}
	int l=1,r=sy.size();
	while(l<r){
		if(sy[l]!=sy[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}
