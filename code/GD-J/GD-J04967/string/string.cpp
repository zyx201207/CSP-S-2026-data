#include <bits/stdc++.h>
using namespace std;
int n;
long long l,r,ans;
struct Node {
	long long x;
	char c;
}a[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	l=1;
	r=n;
	long long l_num=a[l].x,r_num=a[r].x;
	while(l<r){
		if(l_num<r_num){
			if(a[l].c!=a[r].c)ans+=l_num;
			r_num-=l_num;
			l++;
			l_num=a[l].x;
		}else{
			if(l_num>r_num){
				if(a[l].c!=a[r].c)ans+=r_num;
				l_num-=r_num;
				r--;	
				r_num=a[r].x;		
			}else{
				if(a[l].c!=a[r].c)ans+=r_num;
				l++;
				r--;
				l_num=a[l].x;
				r_num=a[r].x;
			}
		}
	}
	cout<<ans;
	return 0;
}
