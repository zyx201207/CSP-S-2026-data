#include<bits/stdc++.h>
using namespace std;
struct str{
	string s1;
	long long a;
};
bool cmp(str c,str d){
	return c.a>d.a;
}
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	cin.tie(0);
	cin>>n>>m;
	str t[n+1];
	for(long long i=1;i<=n;i++){
		cin>>t[i].a;
	}
	long long x;
	for(long long i=1;i<=n;i++){
		long long x=t[i].a;
		string s;
		while(x>1){
			s+=x%2;
			x/=2;
		}
		s+=x;
		long long l=s.size();
		for(long long j=l-1;j>=0;j--){
			t[i].s1+=s[i];
		}
	}
	if(m==1){
		sort(t+1,t+1+n,cmp);
		cout<<t[1].s1;
	}else if(m==2){
		for(long long i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(t[i].a==t[j].a){
					cout<<t[i].a;
				}
			}
		}
		
	}
	return 0;
} 
