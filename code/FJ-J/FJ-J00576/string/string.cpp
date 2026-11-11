#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m;
struct P{
	long long a;
	char c;	
}p[N]; 

char l_now,r_now;
long long l_len=0,r_len=0;
long long ans;
signed main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n;
//cout<<n<<"\n";
for(int i=1;i<=n;i++){
	cin>>p[i].a>>p[i].c;
//	cout<<p[i].a<<" "<<p[i].c<<"\n";
	}
long long idl=0,idr=n+1;
while(idl<=n&&idr>=1){
	
	if(l_len==0){
		idl++;
		l_len=p[idl].a;
		l_now=p[idl].c;
	}
	if(r_len==0){
		idr--;
		r_len=p[idr].a;
		r_now=p[idr].c;
	}
//	cout<<idl<<" "<<l_len<<" "<<l_now<<" "<<idr<<" "<<r_len<<" "<<r_now<<"\n";
	if(l_now!=r_now){
		if(l_len<r_len){
			ans+=l_len;
		}
		else if(l_len>r_len){
			ans+=r_len;
		}	
		else ans+=l_len;
	}
	if(l_len<r_len){
			r_len=r_len-l_len;
			l_len=0;
			l_now=' ';
		}
		else if(l_len>r_len){
			l_len=l_len-r_len;
			r_len=0;
			r_now=' ';
		}
		else {
			l_len=0;
			r_len=0;
			l_now=' ';
			r_now=' ';
		}
	
}
cout<<ans/2;
return 0;
}

