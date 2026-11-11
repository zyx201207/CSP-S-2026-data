#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,sum,ans;
struct STRING{
	int a;
	char c;
};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
/*	cin>>n;
	STRING s[n+1];
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		ans+=s[i].a;
	}
	int MAX=n/2;
	for(int i=1;i<=n;i++){
		int N=ans+1-i;
		if(s[i].a<=MAX){
			while(s[i].a==0){
				if(s[i].c!=s[N].c){
					if(s[i].a>=s[N].a){
						sum+=s[N].a;
						s[i].a-=s[N].a;
						MAX-=s[N].a;
						N--;
					}else if(s[i].a<s[N].a){
						sum+=s[i].a;
						s[N].a-=s[i].a;
						MAX-=s[i].a;
						s[i].a=0;
					}
				}else if(s[i].c==s[N].c){
					if(s[i].a>=s[N].a){
						s[i].a-=s[N].a;
					}else if(s[i].a<s[N].a){
						s[N].a-=s[i].a;
						s[i].a=0;
					}
				}
				
			}
		}else if(s[i].a<MAX){
			sum+=(2*MAX)-s[N].a;
		}
	}
	cout<<sum;
*/
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int a;
		string c;
		cin>>a>>c;
		for(int i=0;i<a;i++){
			s+=c;
		}
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) sum++;
	}
	cout<<sum;
	return 0;
} 
