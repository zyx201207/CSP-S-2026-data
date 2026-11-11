#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
struct Node{
	long long a;
	char c;
}s[N];
long long len1,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,w=0;
	cin>>n;
	for(int i=1,j=0;i<=n;i++){
		long long a1;char c1;
		cin>>a1>>c1;
		if(c1==s[j].c&&i!=1){
			s[j].a+=a1;w++;
		} else {
			j++;
			s[j].a=a1,s[j].c=c1;
		}
		len1+=a1;
	}n-=w;
	if(n<=1){
		cout<<0;
		return 0;
	}
	if(len1%2==1){
		int t=len1/2+1,ti=1;
		while(t>s[ti].a){
			t-=s[ti].a;
			ti++;
		}
		s[ti].a=s[ti].a-t-t+1;
		int l=ti-1,r=ti;
		while(l>=1&&r<=n){
			if(s[l].c!=s[r].c){
				if(s[l].a>s[r].a){
					ans+=s[r].a;
					s[l].a-=s[r].a;
					r++;
				}
				else if(s[l].a>s[r].a){
					ans+=s[l].a;
					s[r].a-=s[l].a;
					l++;
				}
				else{
					ans+=s[l].a;
					l++;
					r++;
				}
			}
			else{
				if(s[l].a>s[r].a){
					s[l].a-=s[r].a;
					r++;
				}
				else if(s[l].a>s[r].a){
					s[r].a-=s[l].a;
					l++;
				}
				else{
					l++;
					r++;
				}
			}
		}cout<<ans;
	}
	else{
		int t=len1/2,ti=1;
		while(t>=s[ti].a){
			t-=s[ti].a;
			ti++;
		}
		int l=ti-1,r=ti;
		while(l>=1&&r<=n){
			if(s[l].c!=s[r].c){
				if(s[l].a>s[r].a){
					ans+=s[r].a;
					s[l].a-=s[r].a;
					r++;
				}
				else if(s[l].a>s[r].a){
					ans+=s[l].a;
					s[r].a-=s[l].a;
					l++;
				}
				else{
					ans+=s[l].a;
					l++;
					r++;
				}
			}
			else{
				if(s[l].a>s[r].a){
					s[l].a-=s[r].a;
					r++;
				}
				else if(s[l].a>s[r].a){
					s[r].a-=s[l].a;
					l++;
				}
				else{
					l++;
					r++;
				}
			}
		}cout<<ans;
	}
	return 0;
}
