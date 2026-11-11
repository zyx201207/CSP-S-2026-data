#include<bits/stdc++.h>
using namespace std;
#define int long long
const int M=2e5+10; 
int f[M];
struct node{
	int a,len_a;
	char c;
}s[M];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	long long len=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		len+=s[i].a,s[i].len_a=len;
	}
	int endi;
	for(int i=1;i<=n;i++)
		if(s[i].len_a>=(len+1)/2){
			endi=i;
			break;
		}
	int l=1,r=n;
	long long ans=0;
	while((l<=endi&&r>=endi)&&l!=r){
		if(s[l].c!=s[r].c){
			if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				ans+=s[r].a,r--;
			}
			else{
				s[r].a-=s[l].a;
				ans+=s[l].a,l++;
			}
		}
		else{
			if(s[l].a>s[r].a) s[l].a-=s[r].a,r--;
			else s[r].a-=s[l].a,l++;
		}
	}
	cout<<ans;
	return 0;
}

